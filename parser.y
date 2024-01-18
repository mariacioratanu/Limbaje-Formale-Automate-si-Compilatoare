%{

#include <iostream>
#include <vector>
#include "parser.h"
#include <cstring>
#include <cstdio>

using namespace std;

extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();

vector<Parametru> globalParams; //vector pentru stocarea parametrilor globali
class IdList ids; //clasa pentru gestionarea identificatorilor
string context = "global"; //contextul curent, initial global
string altcontext; //context alternativ pentru situatii specifice
vector<int> intValvec; //vector pentru stocarea valorilor intregi
vector<float> floatValvec; 
vector<char> charValvec; 
vector<bool> boolValvec; 
vector<Valoare> parametri;

void yyerror(const char * s);
%}


%union 
{
     char* string; 
     int integer; 
     int boolean; 
     char character; 
     float floatnum; 
     class AST* ASTNode; //tipul de date pentru nodurile arborelui de sintaxa abstracta (AST)
     class Parametru* parametri; //tipul de date pentru parametri
     class Variabila* var; //tipul de date pentru variabile
}

%token VARS FUNCS CONSTRUCTS //cuvinte cheie pentru declararea de variabile, functii si constructori
%token CLASS CONST //cuvinte cheie pentru declararea de clase si constante
%token NEQ GT GEQ LT LEQ AND OR NOT //operatori relationali si logici
%token IF ELSE WHILE FOR SWITCH CASE //cuvinte cheie pentru structuri de control
%token ENTRY EXIT MAIN FNENTRY BREAK DEFAULT USRDEF GLOBALVAR GLOBALFUNC RETURN PRINT //cuvinte cheie specifice
%token<string> ID TYPE EVAL TYPEOF STRING //token-uri pentru siruri de caractere, identificatori de tip, evaluare, tipizare si siruri de caractere
%token<integer> INT 
%token<character> CHAR 
%token<floatnum> FLOAT 
%token<boolean> BOOL 

%left OR  //specificam prioritatea operatorilor logici
%left AND
%left NOT
%left EQ NEQ //specificam prioritatea operatorilor relationali
%left LEQ GEQ LT GT

%left '+' '-'      //specificam prioritatea operatorilor aritmetici
%left '*' '/' '%' 
%left '(' ')'      //specificam prioritatea parantezelor
%start program     //specificam simbolul de start

%type <ASTNode> arithm_expr bool_expr expression //specificam tipul de date al unor nonterminale
%type <param> parameter
%type <var> fn_call

%%
//structura generala a programului
program: ENTRY USRDEF user_defined_types GLOBALVAR global_variables GLOBALFUNC global_functions MAIN { context = "main"; } '{' block '}' EXIT {printf("Totul a decurs bine!\n");}
       ;

user_defined_types: 
                  | user_defined_types user_defined_type
                  ;

user_defined_type: CLASS ID { if(ids.existaClasa($2)) {printf("Error at line %d: the class \"%s\" is already defined.\n", yylineno, $2); return 1;} context = $2; 
                        UserDefinedType type($2);
                        ids.adaugaUsrDef(type);} 
                        '{' VARS field_variables FUNCS field_functions CONSTRUCTS field_constructors'}' ';' {
                        context = "global";
}
                 ;
//modul în care sunt definite variabilele membru ale unei clase. lista goala / contine declaratii de variabile sau vectori
field_variables:  {} 
               | field_variables variable_declaration {  }
               | field_variables array_declaration { }
	          ;

//modul in care sunt definite functiile membru ale unei clase
field_functions:  { }
               | field_functions function_declaration { }
	       ;
//modul in care este declarata o functie:
function_declaration: FNENTRY TYPE ID  {    altcontext=context;
                                            int result=ids.existaFunctia($3, altcontext);
                                            if(result==1) 
                                            {
                                                printf("Error at line %d: the function \"%s\" is already defined inside this scope: %s.\n", yylineno, $3, altcontext.c_str());
                                                return 1;
                                            }
                                            else if(result==2) 
                                            {
                                                printf("Error at line %d: return type specification for constructor invalid.\n", yylineno);
                                                return 1;
                                            }
                                            else if(result==3) 
                                            {
                                                printf("Error at line %d: %s already exists as a class variable or array.\n", yylineno, $3);
                                                return 1;
                                            }
                                            Functie func($3, $2, altcontext); 
                                            ids.adaugaFunc(func); 
                                            context=$3; 
                                        } 
                        '(' parameter_list ')' '{' block '}' 
                        {
                                            Functie &func=ids.obtineFunctie(context.c_str());
                                            func.parametri=globalParams;
                                            globalParams.clear();  
                                            context=altcontext;
                        } 
                        ;
//constructorii
field_constructors: { }
                  | field_constructors constructor_declaration { }
              ;
//cum e declarat un constructor pt o clasa 
constructor_declaration: ID {               if (strcmp($1, context.c_str())!= 0)
                                            {
                                                printf("Error at line %d: the constructor should have the same name as the class\n", yylineno);
                                                return 1;
                                            }
                                            altcontext=context;
                                            Functie func($1, "none (CONSTRUCTOR)", altcontext); 
                                            ids.adaugaFunc(func); 
                                            context=$1; 
                            }
                            '(' parameter_list ')' '{' constructor_block '}' 
                            { 
                                Functie &func=ids.obtineFunctie(context.c_str());
                                func.parametri=globalParams;
                                globalParams.clear();
                                context=altcontext; 
                            } 
                        ;

constructor_block : block//defineste blocul pentru constructor - fie un bloc obisnuit de cod, fie un bloc gol
                  | {}
                  ;

global_variables: //defineste variabilele globale; permite declararea de noi variabile, array-uri sau variabile de clasa
                  | global_variables variable_declaration
                  | global_variables array_declaration
                  | global_variables class_var_declaration
                  ;

global_functions: //defineste functiile globale; permite adaugarea de noi declaratii de functii
                | global_functions function_declaration
                ;

parameter_list:  {} //defineste lista de parametri; permite adaugarea de parametri noi sau nu adauga nimic daca lista este goala
               | parameter { } 
               | parameter_list ',' parameter  { } 
               ;


parameter: TYPE ID  //defineste un parametru cu un tip si un identificator; verific daca parametrul a fost deja declarat
{ 
            for(const auto &param: globalParams)
            {
                if(param.nume==$2)
                {
                    printf("Error at line %d: parameter \"%s\" declared more than once for this function.\n", yylineno, $2);
                    return 1;
                }
            }
    globalParams.push_back(Parametru($2, $1));} 
         | CONST TYPE ID { 
            for(const auto &param: globalParams)
            {
                if(param.nume==$3)
                {
                    printf("Error at line %d: parameter \"%s\" declared more than once for this function.\n", yylineno, $3);
                return 1;
                }
            }
            Parametru param($3, $2);
            param.esteConstanta=true; 
            globalParams.push_back(param);
         }
        ;

variable_declaration: TYPE ID ';' //defineste o declaratie de variabila; verifica daca variabila exista deja in contextul curent
{
                        int result=ids.exista($2, context);
                        if(result==1)
                        {
                            printf("Error at line %d: \"%s\" already exists as a variable or array in this scope.\n", yylineno, $2);
                            return 1;
                        } 
                        else if(result==2)
                        {
                            printf("Error at line %d: \"%s\" already exists as a function.\n", yylineno, $2);
                            return 1;
                        }
                        else if(result==3)
                        {
                            printf("Error at line %d: \"%s\" already exists as a user defined type.\n", yylineno, $2);
                            return 1;
                        }
                        else 
                        {
                            Valoare val($1);
                            Variabila var($2, val);
                            var.context=context;
                            ids.adaugaVar(var);
                        }
                    }
                    | TYPE ID '=' CHAR ';' //defineste o variabila de tip char si initializeaza cu o valoare data
                    {
                        string tipul="char";
                        int result=ids.exista($2, context);
                        if(result==1)
                        {
                            printf("Error at line %d: \"%s\" already exists as a variable or array in this scope.\n", yylineno, $2);
                            return 1;
                        } 
                        else if(result==2)
                        {
                            printf("Error at line %d: \"%s\" already exists as a function.\n", yylineno, $2);
                            return 1;
                        }
                        else if(result==3)
                        {
                            printf("Error at line %d: \"%s\" already exists as a user defined type.\n", yylineno, $2);
                            return 1;
                        }
                        else if($1==tipul)
                        {
                            Valoare val(tipul);
                            val.isCharSet=true;
                            val.charVal=$4;
                            Variabila var($2, val);
                            var.context=context;
                            ids.adaugaVar(var);
                        }  else 
                        {
                            printf("Error at line %d: Different types.1\n", yylineno);
                            return 1;
                        }                     
                    }
                    | TYPE ID '=' STRING ';' 
                    {
                        string tipul="string";
                        int result=ids.exista($2, context);
                        if(result==1)
                        {
                            printf("Error at line %d: \"%s\" already exists as a variable or array in this scope.\n", yylineno, $2);
                            return 1;
                        } 
                        else if(result==2)
                        {
                            printf("Error at line %d: \"%s\" already exists as a function.\n", yylineno, $2);
                            return 1;
                        }
                        else if(result==3)
                        {
                            printf("Error at line %d: \"%s\" already exists as a user defined type.\n", yylineno, $2);
                            return 1;
                        } else if($1==tipul)
                        {
                            Valoare val(tipul);
                            val.isStringSet=true;
                            val.stringVal=$4;
                            Variabila var($2, val);
                            var.context=context;
                            ids.adaugaVar(var);
                        }  else 
                        {
                            printf("Error at line %d: Different types.2\n", yylineno);
                            return 1;
                        }                     
                    }
                    | TYPE ID '=' expression ';' 
                    {
                        int result=ids.exista($2, context);
                        if(result==1)
                        {
                            printf("Error at line %d: \"%s\" already exists as a variable or array in this scope.\n", yylineno, $2);
                            return 1;
                        } 
                        else if(result==2)
                        {
                            printf("Error at line %d: \"%s\" already exists as a function.\n", yylineno, $2);
                            return 1;
                        }
                        else if(result==3)
                        {
                            printf("Error at line %d: \"%s\" already exists as a user defined type.\n", yylineno, $2);
                            return 1;
                        }
                        if($1==$4->Eval().tipul) 
                        {
                            Valoare val($1);
                            if(val.tipul=="int") 
                            {
                                val.isIntSet=true;
                                val.intVal=$4->Eval().intVal;
                            } else if(val.tipul=="float") 
                            {
                                val.isFloatSet=true;
                                val.floatVal=$4->Eval().floatVal;
                            } else if(val.tipul=="bool") 
                            {
                                val.isBoolSet=true;
                                val.boolVal=$4->Eval().boolVal;
                            }        
                            Variabila var($2, val);
                            var.context=context;
                            ids.adaugaVar(var);
                        } else 
                        {
                            printf("Error at line %d: Different types.3\n", yylineno);
                            return 1;
                        }
                    } 
                    | CONST TYPE ID ';'  
                    { 
                        int result=ids.exista($3, context);
                        if(result==1)
                        {
                            printf("Error at line %d: \"%s\" already exists as a variable or array in this scope.\n", yylineno, $3);
                            return 1;
                        } 
                        else if(result==2)
                        {
                            printf("Error at line %d: \"%s\" already exists as a function.\n", yylineno, $3);
                            return 1;
                        }
                        else if(result==3)
                        {
                            printf("Error at line %d: \"%s\" already exists as a user defined type.\n", yylineno, $3);
                            return 1;
                        }
                        else 
                        {
                            Valoare val($2);
                            val.esteConstanta=true;
                            Variabila var($3, val);
                            var.context=context;
                            ids.adaugaVar(var);
                        }
                    }
                    | CONST TYPE ID '=' expression ';'  
                    { 
                        int result=ids.exista($3, context);
                        if(result==1)
                        {
                            printf("Error at line %d: \"%s\" already exists as a variable or array in this scope.\n", yylineno, $3);
                            return 1;
                        } 
                        else if(result==2)
                        {
                            printf("Error at line %d: \"%s\" already exists as a function.\n", yylineno, $3);
                            return 1;
                        }
                        else if(result==3)
                        {
                            printf("Error at line %d: \"%s\" already exists as a user defined type.\n", yylineno, $3);
                            return 1;
                        }
                        if ($2 == $5->TypeOf()) 
                        {
                            Valoare val($2);
                            val.esteConstanta=true;
                            if(val.tipul=="int") 
                            {
                                val.isIntSet=true;
                                val.intVal=$5->Eval().intVal;
                            } 
                            else if(val.tipul=="float") 
                            {
                                val.isFloatSet=true;
                                val.floatVal=$5->Eval().floatVal;
                            } else if(val.tipul=="bool") 
                            {
                                val.isBoolSet=true;
                                val.boolVal=$5->Eval().boolVal;
                            } 
                            Variabila var($3, val);
                            var.context=context;
                            ids.adaugaVar(var);
                        } 
                        else 
                        {
                            printf("Error at line %d: Different types.4\n", yylineno);
                            return 1;
                        }
                        
                    }
                    | CONST TYPE ID '=' CHAR ';'  
                    { 
                        int result=ids.exista($3, context);
                        if(result==1)
                        {
                            printf("Error at line %d: \"%s\" already exists as a variable or array in this scope.\n", yylineno, $3);
                            return 1;
                        } 
                        else if(result==2)
                        {
                            printf("Error at line %d: \"%s\" already exists as a function.\n", yylineno, $3);
                            return 1;
                        }
                        else if(result==3)
                        {
                            printf("Error at line %d: \"%s\" already exists as a user defined type.\n", yylineno, $3);
                            return 1;
                        }
                       string tipul="char";
                        if($2==tipul) 
                        {
                            Valoare val($2);
                            val.esteConstanta=true;
                            val.charVal=$5;
                            val.isCharSet=true;
                            Variabila var($3, val);
                            var.context=context;
                            ids.adaugaVar(var);
                        } 
                        else 
                        {
                            printf("Error at line %d: Different types.5\n",yylineno);
                            return 1;
                        }
                        
                    }
                    | CONST TYPE ID '=' STRING ';'  
                    { 
                        int result=ids.exista($3, context);
                        if(result==1)
                        {
                            printf("Error at line %d: \"%s\" already exists as a variable or array in this scope.\n", yylineno, $3);
                            return 1;
                        } 
                        else if(result==2)
                        {
                            printf("Error at line %d: \"%s\" already exists as a function.\n", yylineno, $3);
                            return 1;
                        }
                        else if(result==3)
                        {
                            printf("Error at line %d: \"%s\" already exists as a user defined type.\n", yylineno, $3);
                            return 1;
                        }
                        string tipul="string";
                        if($2==tipul) 
                        {
                            Valoare val($2);
                            val.esteConstanta=true;
                            val.stringVal=$5;
                            val.isStringSet=true;
                            Variabila var($3, val);
                            var.context=context;
                            ids.adaugaVar(var);
                        } 
                        else 
                        {
                            printf("Error at line %d: Different types.6\n",yylineno);
                            return 1;
                        }
                        
                    }
                    ;


                                                        
class_var_declaration: CLASS ID ID ';' 
{
                            if(!ids.existaClasa($2))
                            {
                                printf("Error at line %d: the class \"%s\" is not defined.\n", yylineno, $2);
                                return 1;
                            }
                            int result=ids.exista($3, context);
                            if( result==1 )
                            {
                            printf("Error at line %d: \"%s\" already exists as a variable or array in this scope.\n", yylineno, $3);
                            return 1;
                            } 
                            else if(result==2)
                            {
                                printf("Error at line %d: \"%s\" already exists as a function.\n", yylineno, $3);
                                return 1;
                            }
                            else if (result == 3)
                            {
                                printf("Error at line %d: \"%s\" already exists as a user defined type.\n", yylineno, $3);
                                return 1;
                            } 
                            else 
                            {
                                Valoare val($2);
                                Variabila var($3, val);
                                var.context = context;
                                ids.adaugaVar(var);
                            }
                            
                     }
                     | CLASS ID ID '=' ID ';' 
                     { 
                            if(!ids.existaClasa($2))
                            {
                                printf("Error at line %d: the class \"%s\" is not defined.\n", yylineno, $2);
                                return 1;
                            }
                            int result = ids.exista($3, context);
                            if( result == 1 )
                            {
                            printf("Error at line %d: \"%s\" already exists as a variable or array in this scope.\n", yylineno, $3);
                            return 1;
                            } 
                            else if (result == 2)
                            {
                                printf("Error at line %d: \"%s\" already exists as a function.\n", yylineno, $3);
                                return 1;
                            }
                            else if (result == 3)
                            {
                                printf("Error at line %d: \"%s\" already exists as a user defined type.\n", yylineno, $3);
                                return 1;
                            } else 
                            {
                                
                                if ( !ids.exista($5) )
                                {
                                printf("Error at line %d: No %s variable found.\n",yylineno, $5);
                                return 1;
                                }
                                
                                
                                if( ids.obtineVariabila($5).Eval().tipul != $2) 
                                {
                                    printf("Error at line %d: Different types between %s and %s.\n",yylineno, $3, $5);
                                    return 1;
                                }
                                Valoare val($2);
                                Variabila var($3, val);
                                var.context = context;
                                ids.adaugaVar(var);
                            }   
                     }
                     ;
                     
array_declaration: TYPE ID '[' INT ']' ';' 
{
                    int result = ids.exista($2, context);
                        if( result == 1 )
                        {
                            printf("Error at line %d: \"%s\" already exists as a variable or array in this scope.\n", yylineno, $2);
                            return 1;
                        } 
                        else if (result == 2)
                        {
                            printf("Error at line %d: \"%s\" already exists as a function.\n", yylineno, $2);
                            return 1;
                        }
                        else if (result == 3)
                        {
                            printf("Error at line %d: \"%s\" already exists as a user defined type.\n", yylineno, $2);
                            return 1;
                        } 
                        else 
                        {
                        Vector arr($2, $4, $1);
                        arr.context = context;
                        ids.adaugaVec(arr);
                        }
                 }
                 | TYPE ID '[' ']' '=' '[' int_valori ']' ';' 
                 {
                   int result = ids.exista($2, context);
                        if( result == 1 )
                        {
                            printf("Error at line %d: \"%s\" already exists as a variable or array in this scope.\n", yylineno, $2);
                            return 1;
                        } 
                        else if (result == 2)
                        {
                            printf("Error at line %d: \"%s\" already exists as a function.\n", yylineno, $2);
                            return 1;
                        }
                        else if (result == 3)
                        {
                            printf("Error at line %d: \"%s\" already exists as a user defined type.\n", yylineno, $2);
                            return 1;
                        } 
                        else 
                        {
                        Vector arr($2, static_cast<int>(intValvec.size()), $1);
                        
                        for (const auto &element : intValvec) 
                        {
                            char val[10];
                            sprintf(val, "%d", element);
                            arr.push(Valoare(val, "int"));
                        }

                        intValvec.clear();
                        arr.context = context;
                        ids.adaugaVec(arr);
                        
                    }
                 }
                 | TYPE ID '[' ']' '=' '[' float_valori ']' ';' 
                 {
                    int result = ids.exista($2, context);
                        if( result == 1 )
                        {
                            printf("Error at line %d: \"%s\" already exists as a variable or array in this scope.\n", yylineno, $2);
                            return 1;
                        } 
                        else if (result == 2)
                        {
                            printf("Error at line %d: \"%s\" already exists as a function.\n", yylineno, $2);
                            return 1;
                        }
                        else if (result == 3)
                        {
                            printf("Error at line %d: \"%s\" already exists as a user defined type.\n", yylineno, $2);
                            return 1;
                        } 
                        else 
                        {
                        Vector arr($2, static_cast<int>(floatValvec.size()), $1);
                        
                        for (const auto &element : floatValvec) 
                        {
                            char val[64];
                            sprintf(val, "%f", element);
                            arr.push(Valoare(val, "float"));
                        }
                        
                        arr.context = context;
                        ids.adaugaVec(arr);
                        floatValvec.clear();
                        }
                 }
                 | TYPE ID '[' ']' '=' '[' char_valori ']' ';' 
                 {
                   int result = ids.exista($2, context);
                        if( result == 1 ){
                            printf("Error at line %d: \"%s\" already exists as a variable or array in this scope.\n", yylineno, $2);
                            return 1;
                        } 
                        else if (result == 2)
                        {
                            printf("Error at line %d: \"%s\" already exists as a function.\n", yylineno, $2);
                            return 1;
                        }
                        else if (result == 3)
                        {
                            printf("Error at line %d: \"%s\" already exists as a user defined type.\n", yylineno, $2);
                            return 1;
                        } else {
                        Vector arr($2, static_cast<int>(charValvec.size()), $1);
                        
                        for (const auto &element : charValvec) {
                            char val[10];
                            sprintf(val, "%c", element);
                            arr.push(Valoare(val, "char"));
                        }
                        
                        arr.context = context;
                        ids.adaugaVec(arr);
                        charValvec.clear();
                    }
                 }
                 | TYPE ID '[' ']' '=' '[' bool_valori ']' ';' {
                    int result = ids.exista($2, context);
                        if( result == 1 ){
                            printf("Error at line %d: \"%s\" already exists as a variable or array in this scope.\n", yylineno, $2);
                            return 1;
                        } 
                        else if (result == 2)
                        {
                            printf("Error at line %d: \"%s\" already exists as a function.\n", yylineno, $2);
                            return 1;
                        }
                        else if (result == 3)
                        {
                            printf("Error at line %d: \"%s\" already exists as a user defined type.\n", yylineno, $2);
                            return 1;
                        } else {
                        Vector arr($2, static_cast<int>(boolValvec.size()), $1);
                        
                        for (const auto &element : boolValvec) { 
                            char val[6];
                            if (element){
                                strcpy(val, "true");
                            } else {
                                strcpy(val, "false");
                            }
                            arr.push(Valoare(val, "bool"));
                        }
                        arr.context = context;
                        ids.adaugaVec(arr);
                        boolValvec.clear();
                    }
                 }
                 ;
                 
int_valori: int_valori ',' INT {intValvec.push_back($3);}
          | INT {intValvec.push_back($1);}
          ;
          
float_valori: float_valori ',' FLOAT {floatValvec.push_back($3);}
            | FLOAT {floatValvec.push_back($1);}
            ;
            
bool_valori: bool_valori ',' BOOL {boolValvec.push_back($3);}
           | BOOL {boolValvec.push_back($1);}
           ;
           
char_valori: char_valori ',' CHAR {charValvec.push_back($3);}
           | CHAR {charValvec.push_back($1);}
           ;

block: statement
     | block statement
     ;

statement: variable_declaration
         | array_declaration
         | class_var_declaration
         | assignment_statement
         | control_statement 
         | fn_call ';'
         | RETURN expression ';' {
            if ( context == "main" ) {
                if ( $2->Eval().tipul != "int" ){
                    printf("Error at line %d: Error at returning a non integer in main scope.\n", yylineno);
                    return 1;
                }

            } else {
                Functie fn = ids.obtineFunctie(context.c_str());
                if( fn.returnType != $2->Eval().tipul ){
                    printf("Error at line %d: Different returning types in function: %s.\n", yylineno, fn.nume.c_str());
                    return 1;
                } 
            }
         }
         | RETURN STRING ';' {
            if ( context == "main") {
                printf("Error at line %d: Error at returning a non integer in main scope.\n",yylineno);
                return 1;
            } else {
                Functie fn = ids.obtineFunctie(context.c_str());
                string tipul = "string";
                if( fn.returnType != tipul ){
                    printf("Error at line %d: Different returning types in function: %s.\n",yylineno, fn.nume.c_str());
                    return 1;
                }
            }
         }
         | RETURN CHAR ';' {
            if ( context == "main") {
                printf("Error at line %d: Error at returning a non integer in main scope.\n",yylineno);
                return 1;
            } else {
                Functie fn = ids.obtineFunctie(context.c_str());
                string tipul = "char";
                if( fn.returnType != tipul ){
                    printf("Error at line %d: Different returning types in function: %s.\n",yylineno, fn.nume.c_str());
                    return 1;
                }
            }
         }
         | TYPEOF '(' expression ')' ';' {
            printf("linia : %d Tipul expresiei este: %s\n",yylineno, $3->Eval().tipul.c_str());
         }
         | EVAL '(' expression ')' ';' {
            string tipul = $3->TypeOf();
            if( tipul == "int" ) {
                printf("linia : %d Valoarea expresiei este: %d\n",yylineno, $3->Eval().intVal);
            } else if( tipul == "float" ) {
                printf("linia : %d Valoarea expresiei este: %f\n",yylineno, $3->Eval().floatVal);
            } else if( tipul == "char" ) {
                printf("linia : %d Valoarea expresiei este: %c\n",yylineno, $3->Eval().charVal);
            } else if( tipul == "bool" ) {
                if( $3->Eval().boolVal != 0 ){
                    printf("linia : %d Valoarea expresiei este: true \n",yylineno);
                } else {
                    printf("linia : %d Valoarea expresiei este: false\n",yylineno);
                } 
            }
         }
         ;

assignment_statement: ID '=' expression ';' {
                        if( ids.exista($1) ) {
                            Valoare result = $3->Eval();
                            Variabila& var = ids.obtineVariabila($1);
                            if(var.val.esteConstanta) {
                                printf("Error at line %d: Cannot assign value to a constant variable.\n", yylineno);
                                return 1;
                            }
                            if (var.context == context || var.context == "global" || (ids.exista(context.c_str()) && var.context == ids.obtineFunctie(context.c_str()).context) ) {
                                if (var.val.tipul == $3->TypeOf()){
                                if (var.val.tipul == "int") {
                                    var.val.isIntSet = true;
                                    var.val.intVal = result.intVal;
                                } else if (var.val.tipul == "float") {
                                    var.val.isFloatSet = true;
                                    var.val.floatVal = result.floatVal;
                                } else if (var.val.tipul == "bool") {
                                    var.val.isBoolSet = true;
                                    var.val.boolVal = result.boolVal;
                                }
                            } else {
                                printf("Error at line %d: Different types.\n", yylineno);
                                return 1;
                            } 
                            } else {
                                printf("Error at line %d: Variable not found in this scope.\n", yylineno);
                                return 1;
                            }                   
                        } else {
                            printf("Error at line %d: Variable not found.1\n", yylineno);
                            return 1;
                        }
                    }
                    | ID '=' CHAR ';' {
                        if( ids.exista($1) ) {

                            Variabila& var = ids.obtineVariabila($1);
                            if(var.val.esteConstanta) {
                                printf("Error at line %d: Cannot assign value to a constant variable.\n", yylineno);
                                return 1;
                            }
                            if (var.context == context || var.context == "global" || (ids.exista(context.c_str()) && var.context == ids.obtineFunctie(context.c_str()).context) ) {
                                if (var.val.tipul == "char"){
                                    var.val.isCharSet = true;
                                    var.val.charVal = $3;  
                                } else {
                                    printf("Error at line %d: Different types.7\n", yylineno);
                                    return 1;
                                }  
                            } else {
                                printf("Error at line %d: Variable not found in this scope.\n", yylineno);
                                return 1;
                            } 

                        } else {
                            printf("Error at line %d: Variable not found.2\n",yylineno);
                            return 1;
                        }
                    }
                    | ID '=' STRING ';' {
                        if( ids.exista($1) ) {
                            Variabila& var = ids.obtineVariabila($1);
                            if(var.val.esteConstanta) {
                                printf("Error at line %d: Cannot assign value to a constant variable.\n", yylineno);
                                return 1;
                            }
                            if (var.context == context || var.context == "global" || (ids.exista(context.c_str()) && var.context == ids.obtineFunctie(context.c_str()).context) ) {
                                if (var.val.tipul == "string"){
                                    var.val.isStringSet = true;
                                    var.val.stringVal = $3;  
                                } else {
                                    printf("Error at line %d: Different types.8\n", yylineno);
                                    return 1;
                                }  
                            } else {
                                printf("Error at line %d: Variable not found in this scope.\n", yylineno);
                                return 1;
                            }
                        } else {
                            printf("Error at line %d: Variable not found.3\n", yylineno);
                            return 1;
                        }
                    }
                    | ID '[' INT ']' '=' expression ';' {
                        Valoare result = $6->Eval();
                        if( ids.exista($1) ) {   
                            Vector& arr = ids.obtineVector($1);
                            if (arr.context == context || arr.context == "global" || (ids.exista(context.c_str()) && arr.context == ids.obtineFunctie(context.c_str()).context) ) {
                                if (arr.tipul == result.tipul){
                                    arr.adauga($3, result);
                                } else {
                                    printf("Error at line %d: Different types.9\n",yylineno);
                                    return 1;
                                }   
                            } else {
                                printf("Error at line %d: Variable not found in this scope.\n", yylineno);
                                return 1;
                            }
                        } else {
                            printf("Error at line %d: Variable not found.4\n",yylineno);
                            return 1;
                        }
                    }
                    | ID '[' INT ']' '=' CHAR ';' {
                        if( ids.exista($1)) {
                            Vector& arr = ids.obtineVector($1);
                            if (arr.context == context || arr.context == "global" || (ids.exista(context.c_str()) && arr.context == ids.obtineFunctie(context.c_str()).context) ) {
                                if (arr.tipul == "char"){
                                    Valoare val("char");
                                    val.charVal = $6;
                                    val.isCharSet = true;
                                    val.tipul = "char";
                                    arr.adauga($3, val);
                                } else {
                                    printf("Error at line %d: Different types.10\n", yylineno);
                                    return 1;
                                } 
                            } else {
                                printf("Error at line %d: Variable not found in this scope.\n", yylineno);
                                return 1;
                            }  

                        } else {
                            printf("Error at line %d: Variable not found.5\n", yylineno);
                            return 1;
                        }
                    }
                    | ID '[' ID ']' '=' expression ';' {
                        Valoare result = $6->Eval();
                        if( ids.exista($1) && ids.exista($3)) {
                            Vector& arr = ids.obtineVector($1);
                            if (arr.context == context || arr.context == "global" || (ids.exista(context.c_str()) && arr.context == ids.obtineFunctie(context.c_str()).context) ) {
                                Valoare& val = ids.obtineVariabila($3).val;
                                if (arr.tipul == result.tipul && val.tipul == "int"){
                                    arr.adauga(val.intVal, result);
                                } else {
                                    printf("Error at line %d: Different types.11\n", yylineno);
                                    return 1;
                                }  
                            } else {
                                printf("Error at line %d: Variable not found in this scope.\n", yylineno);
                                return 1;
                            }  

                        } else {
                            printf("Error at line %d: Variable not found.6\n", yylineno);
                            return 1;
                        }
                    }
                    | ID '[' ID ']' '=' CHAR ';' {

                        if( ids.exista($1) && ids.exista($3)) {
                            Vector& arr = ids.obtineVector($1);
                            if (arr.context == context  || arr.context == "global" || (ids.exista(context.c_str()) && arr.context == ids.obtineFunctie(context.c_str()).context) ) {
                                Valoare& val = ids.obtineVariabila($3).val;
                                if (arr.tipul == "char" && val.tipul == "int"){
                                    Valoare v("char");
                                    v.charVal = $6;
                                    v.isCharSet = true;
                                    v.tipul = "char";
                                    arr.adauga(val.intVal, v);
                                } else {
                                    printf("Error at line %d: Different types.12\n",yylineno);
                                    return 1;
                                }
                            } else {
                                printf("Error at line %d: Variable not found in this scope.\n", yylineno);
                                return 1;
                            }  

                        } else {
                            printf("Error at line %d: Variable not found.\n", yylineno);
                            return 1;
                        }
                    }
                    | ID '.' ID '=' expression';' {
                        if ( ids.exista($1) && ids.exista($3) && ids.obtineVariabila($3).context == ids.obtineVariabila($1).val.tipul ){
                            Valoare result = $5->Eval();
                            Variabila& var = ids.obtineVariabila($1);
                            if (var.context == context  || var.context == "global" || (ids.exista(context.c_str()) && var.context == ids.obtineFunctie(context.c_str()).context) ) {
                                Variabila& var = ids.obtineVariabila($3);
                                if (var.val.tipul == $5->TypeOf()){
                                if (var.val.tipul == "int") {
                                    var.val.isIntSet = true;
                                    var.val.intVal = result.intVal;
                                } else if (var.val.tipul == "float") {
                                    var.val.isFloatSet = true;
                                    var.val.floatVal = result.floatVal;
                                } else if (var.val.tipul == "bool") {
                                    var.val.isBoolSet = true;
                                    var.val.boolVal = result.boolVal;
                                }
                            } else {
                                printf("Error at line %d: Different types.\n", yylineno);
                                return 1;
                            } 
                            } else {
                                printf("Error at line %d: Variable not found in this scope.\n", yylineno);
                                return 1;
                            } 
                        } else {
                            printf("Error at line %d: Variable not found.\n", yylineno);
                            return 1;
                        }

                    }
                    | ID '.' ID '=' CHAR';' {
                        if ( ids.exista($1) && ids.exista($3) && ids.obtineVariabila($3).context == ids.obtineVariabila($1).val.tipul ){
                            Variabila& var = ids.obtineVariabila($1);
                            if (var.context == context || var.context == "global" || (ids.exista(context.c_str()) && var.context == ids.obtineFunctie(context.c_str()).context) ) {
                                Variabila& var = ids.obtineVariabila($3);
                                if (var.val.tipul == "char"){
                                    var.val.charVal = $5;
                                    var.val.isCharSet = true;
                                } else {
                                    printf("Error at line %d: Different types.\n", yylineno);
                                return 1;
                                }

                            } else {
                                printf("Error at line %d: Variable not found in this scope.\n", yylineno);
                                return 1;
                            } 
                        } else {
                            printf("Error at line %d: Variable not found.\n", yylineno);
                            return 1;
                        }
                    }
                    | ID '.' ID '=' STRING ';' {
                        if ( ids.exista($1) && ids.exista($3) && ids.obtineVariabila($3).context == ids.obtineVariabila($1).val.tipul ){
                            Variabila& var = ids.obtineVariabila($1);
                            if (var.context == context || var.context == "global" || (ids.exista(context.c_str()) && var.context == ids.obtineFunctie(context.c_str()).context) ) {
                                Variabila& var = ids.obtineVariabila($3);
                                if (var.val.tipul == "string"){
                                    var.val.stringVal = $5;
                                    var.val.isStringSet = true;
                                } else {
                                    printf("Error at line %d: Different types.\n", yylineno);
                                return 1;
                                }
                                
                            } else {
                                printf("Error at line %d: Variable not found in this scope.\n", yylineno);
                                return 1;
                            } 
                        } else {
                            printf("Error at line %d: Variable not found.\n", yylineno);
                            return 1;
                        }
                    }
                    ;

control_statement: if_statement 
                 | SWITCH expression'{' case_block DEFAULT ':' block '}'
                 | SWITCH STRING'{' case_block DEFAULT ':' block '}'
                 | SWITCH CHAR'{' case_block DEFAULT ':' block '}'
                 | WHILE bool_expr '{' block '}'
                 | FOR '(' assignment_statement  bool_expr ';' arithm_expr ')' '{' block '}'
                 ;

                 
if_statement: IF bool_expr '{' block '}' ELSE '{' block '}' 
            | IF bool_expr '{' block '}' ELSE if_statement
            ;
            

case_block: CASE valoare ':' block BREAK ';'
          | case_block CASE valoare ':' block BREAK ';'
          ;

valoare: INT
     | FLOAT
     | BOOL
     | fn_call
     | STRING
     ;
            

expression: arithm_expr { $$ = $1; }
          | bool_expr { $$ = $1; }
          ;

 
        
arithm_expr: arithm_expr '+' arithm_expr {
               if($1->Eval().tipul == "bool" || $3->Eval().tipul == "bool"){
                    printf("Error at line %d: Invalid operation between bools.\n", yylineno);
                    return 1;
               }
               if($1->Eval().tipul == "string" || $3->Eval().tipul == "string"){
                    printf("Error at line %d: Invalid operation between strings.\n", yylineno);
                    return 1;
               }
               if ($1->Eval().tipul == $3->Eval().tipul)
                $$ = new AST($1, "+", $3);                
                   
               else{
                    printf("Error at line %d: Different types between: %s and %s.\n", yylineno,$1->Eval().tipul.c_str(), $3->Eval().tipul.c_str());            
                    return 1;
               }

           }
           | arithm_expr '-' arithm_expr {
                if($1->Eval().tipul == "bool" || $3->Eval().tipul == "bool"){
                    printf("Error at line %d: Invalid operation between bools.\n", yylineno);
                    return 1;
               }
               if($1->Eval().tipul == "string" || $3->Eval().tipul == "string"){
                    printf("Error at line %d: Invalid operation between strings.\n", yylineno);
                    return 1;
               }
               if ($1->Eval().tipul == $3->Eval().tipul)
                   $$ = new AST($1, "-", $3); 
               else {
                    printf("Error at line %d: Different types between: %s and %s.\n", yylineno,$1->Eval().tipul.c_str(), $3->Eval().tipul.c_str());
                    return 1;
               }
           }
           | arithm_expr '/' arithm_expr {
            if($1->Eval().tipul == "bool" || $3->Eval().tipul == "bool"){
                    printf("Error at line %d: Invalid operation between bools.\n", yylineno);
                    return 1;
               }
               if($1->Eval().tipul == "string" || $3->Eval().tipul == "string"){
                    printf("Error at line %d: Invalid operation between strings.\n", yylineno);
                    return 1;
               }
               if ($1->Eval().tipul == $3->Eval().tipul)
                   $$ = new AST($1, "/", $3); 
               else {
                    printf("Error at line %d: Different types between: %s and %s.\n", yylineno,$1->Eval().tipul.c_str(), $3->Eval().tipul.c_str());            
                    return 1;
               }
           }
           | arithm_expr '*' arithm_expr {
            if($1->Eval().tipul == "bool" || $3->Eval().tipul == "bool"){
                    printf("Error at line %d: Invalid operation between bools.\n", yylineno);
                    return 1;
               }
               if($1->Eval().tipul == "string" || $3->Eval().tipul == "string"){
                    printf("Error at line %d: Invalid operation between strings.\n", yylineno);
                    return 1;
               }
               if ($1->Eval().tipul == $3->Eval().tipul)
                   $$ = new AST($1, "*", $3); 
               else {
                    printf("Error at line %d: Different types between: %s and %s.\n", yylineno,$1->Eval().tipul.c_str(), $3->Eval().tipul.c_str());            
                    return 1;
               }
           }
           | arithm_expr '%' arithm_expr {
            if($1->Eval().tipul == "bool" || $3->Eval().tipul == "bool"){
                    printf("Error at line %d: Invalid operation between bools.\n", yylineno);
                    return 1;
               }
               if($1->Eval().tipul == "string" || $3->Eval().tipul == "string"){
                    printf("Error at line %d: Invalid operation between strings.\n", yylineno);
                    return 1;
               }
               if ($1->Eval().tipul == $3->Eval().tipul)
                   $$ = new AST($1, "%", $3); 
               else {
                    printf("Error at line %d: Different types between: %s and %s.\n", yylineno, $1->Eval().tipul.c_str(), $3->Eval().tipul.c_str());            
                    return 1;
               }
                    
           }
           | '-' arithm_expr {
                $$ = new AST($2, "-", NULL);
           }
           | '(' arithm_expr ')' {
                $$ = $2;
           }
           | INT {
               char* identifierText = strdup(yytext);
               $$ = new AST(new Valoare(identifierText, "int")); 
           }
           | FLOAT {
               char* identifierText = strdup(yytext);
               $$ = new AST(new Valoare(identifierText, "float")); 
           }
           | fn_call {

                $$ = new AST($1->val);
               
            }
           | ID {
                if( ids.exista($1) ) {
                    Variabila var = ids.obtineVariabila($1);
                    if (var.context == context || var.context == "global" || (ids.exista(context.c_str()) && var.context == ids.obtineFunctie(context.c_str()).context)){
                        Valoare val = var.Eval();
                        $$ = new AST(val);
                    }else {
                        printf("Error at line %d: Variable not found in this scope.\n", yylineno);
                        return 1;
                    }
                    
                } else {
                    printf("Error at line %d: Variable not found.\n", yylineno);
                    return 1;
                }
           }
           | ID '.' ID { 
                if( ids.exista($1) ) {
                    Variabila obj = ids.obtineVariabila($1);
                    if (obj.context == context || obj.context == "global" || (ids.exista(context.c_str()) && obj.context == ids.obtineFunctie(context.c_str()).context)){
                        if( ids.exista($3) ) {
                            Variabila var = ids.obtineVariabila($3);
                            if( var.context == obj.val.tipul ){
                                $$ = new AST(var.val);
                            } else {
                                printf("Error at line %d: No %s member in class %s.\n",yylineno, $3, $1);
                                return 0;
                            }
                                
                        } else {
                            printf("Error at line %d: No %s member in class %s.\n",yylineno, $3, $1);
                            return 0;
                        }

                    } else {
                        printf("Error at line %d: Variable not found in this scope.\n", yylineno);
                        return 1;
                    }
                } else {
                    printf("Error at line %d: Class %s not found.\n",yylineno, $1);
                    return 1;
                }
           } 
           | ID '.' fn_call {
                if( ids.exista($1) ) {
                    Variabila obj = ids.obtineVariabila($1);
                    if (obj.context == context || obj.context == "global" || (ids.exista(context.c_str()) && obj.context == ids.obtineFunctie(context.c_str()).context)){

                        Functie fn = ids.obtineFunctie($3->nume.c_str());

                        if( obj.val.tipul == fn.context ){
                            $$ = new AST($3->val);
                        } else {
                            printf("Error at line %d: No %s method found in class variable %s.", yylineno, $3->nume.c_str(), $1);
                            return 0;
                        }
                        
                    } else {
                        printf("Error at line %d: Variable not found in this scope.\n", yylineno);
                        return 1;
                    }
                    
                } else {

                    printf("Error at line %d: Variable %s not found.\n",yylineno, $1);
                    return 1;

                }
           }
           | ID '[' ID ']' {
                if( ids.exista($1) && ids.exista($3)) {
                    Vector arr = ids.obtineVector($1);
                    if (arr.context == context || arr.context == "global" || (ids.exista(context.c_str()) && arr.context == ids.obtineFunctie(context.c_str()).context)){
                        Valoare val = ids.obtineVariabila($3).Eval();
                        if( val.tipul == "int" )
                            $$ = new AST(arr.obtineValoare(val.intVal));
                        else 
                            printf("Error at line %d: Invalid index type.\n", yylineno);
                    } else {
                        printf("Error at line %d: Variable not found in this scope.\n", yylineno);
                        return 1;
                    }
                } else {
                    printf("Error at line %d: Variable not found.\n", yylineno);
                    return 1;
                }
           }
           | ID '[' INT ']' {
                if( ids.exista($1) ) {
                    Vector arr = ids.obtineVector($1);
                    if (arr.context == context || arr.context == "global" || (ids.exista(context.c_str()) && arr.context == ids.obtineFunctie(context.c_str()).context)){
                        $$ = new AST(arr.obtineValoare($3));
                    } else {
                        printf("Error at line %d: Variable not found in this scope.\n", yylineno);
                        return 1;
                    }
                    
                }else 
                    printf("Error at line %d: Variable not found.\n", yylineno);
           }
           | ID '[' fn_call ']' {
                if( ids.exista($1)) {
                    Vector arr = ids.obtineVector($1);
                    if (arr.context == context || arr.context == "global" || (ids.exista(context.c_str()) && arr.context == ids.obtineFunctie(context.c_str()).context)){
                        if( $3->val.tipul == "int" )
                            $$ = new AST(arr.obtineValoare($3->val.intVal));
                        else 
                            printf("Error at line %d: Invalid index type.\n", yylineno);
                    }
                } else {
                    printf("Error at line %d: Variable not found.\n", yylineno);
                    return 1;
                }
           }
           ;   
               
      
bool_expr: bool_expr AND bool_expr {
               $$ = new AST($1, "and", $3); 
         }
         | bool_expr OR bool_expr {
               $$ = new AST($1, "or", $3); 
           }
         | NOT bool_expr {
               $$ = new AST($2, "not", NULL); 
         }
         | '(' bool_expr ')' {
            $$ = $2;
         }
         | BOOL { 
            char* identifierText = strdup(yytext);
            $$ = new AST(new Valoare(identifierText, "bool"));
          }
         | arithm_expr GT arithm_expr {
               if ($1->Eval().tipul == $3->Eval().tipul)
                   $$ = new AST($1, "gt", $3); 
               else {
                    printf("Error at line %d: Different types between: %s and %s\n", yylineno, $1->Eval().tipul.c_str(), $3->Eval().tipul.c_str());            
                    return 1;
               }
           }
         | arithm_expr LT arithm_expr {
               if ($1->Eval().tipul == $3->Eval().tipul)
                   $$ = new AST($1, "lt", $3); 
               else{
                    printf("Error at line %d: Different types between: %s and %s\n", yylineno, $1->Eval().tipul.c_str(), $3->Eval().tipul.c_str());            
                    return 1;
               }
           }
         | arithm_expr GEQ arithm_expr {
               if ($1->Eval().tipul == $3->Eval().tipul)
                   $$ = new AST($1, "geq", $3); 
               else {
                    printf("Error at line %d: Different types between: %s and %s\n", yylineno, $1->Eval().tipul.c_str(), $3->Eval().tipul.c_str());            
                    return 1;
               }
           }
         | arithm_expr LEQ arithm_expr {
               if ($1->Eval().tipul == $3->Eval().tipul)
                   $$ = new AST($1, "leq", $3); 
               else {
                    printf("Error at line %d: Different types.\n", yylineno);
                    return 1;
               }
                    
           }
         | arithm_expr EQ arithm_expr {
               if ($1->Eval().tipul == $3->Eval().tipul)
                   $$ = new AST($1, "eq", $3); 
               else {
                    printf("Error at line %d: Different types.\n", yylineno);
                    return 1;
               }
           }
         | arithm_expr NEQ arithm_expr {
               if ($1->Eval().tipul == $3->Eval().tipul)
                   $$ = new AST($1, "neq", $3); 
               else {
                    printf("Error at line %d: Different types.\n", yylineno);
                    return 1;
               }
           }
         ;


fn_call: ID '(' argument_list ')' { 
            
            if( ids.exista($1) ) {
                Functie fn = ids.obtineFunctie($1);
                if (fn.context == context || fn.context == "global" || ids.existaVariabila(fn.context.c_str(), context) ){
                        if ( parametri.size() != fn.parametri.size() ){
                        printf("Error at line %d: The %s function call has inapropriate number of parameters.\n", yylineno, fn.nume.c_str());
                        return 1;
                    } else {
                        for( int i = 0; i < parametri.size(); i++ ) {
                            if (parametri.at(i).tipul != fn.parametri.at(i).tipul){
                                printf("Error at line %d: Illegal call params.\n", yylineno);
                                return 1;
                            }
                        }
                        parametri.clear();

                        Valoare result(fn.returnType);
                        if( result.tipul == "int" ){
                            result.intVal = 0;
                            result.isIntSet = true;
                        } else if( result.tipul == "float" ){
                            result.floatVal = 0.0;
                            result.isFloatSet = true;
                        } else if( result.tipul == "bool" ){
                            result.boolVal = true;
                            result.isIntSet = true;
                        } else if( result.tipul == "char" ){
                            result.charVal = '\0';
                            result.isCharSet = true;
                        } else if( result.tipul == "string" ){
                            result.stringVal = "";
                            result.isStringSet = true;
                        }

                        $$ = new Variabila(fn.nume.c_str(), result);

                    }
                } else {
                    printf("Error at line %d: Function not found in this scope.\n", yylineno);
                    return 1;
                }

                
            }
        }
        ;


argument_list: 
             | expression { parametri.push_back($1->Eval());}
             | argument_list ',' expression { parametri.push_back($3->Eval());}
             ;

%%
void yyerror(const char * s) 
{
    std::cerr << "error: " << s << " at line:" << yylineno << std::endl;
}

int main(int argc, char** argv) 
{
    yyin = fopen(argv[1], "r");
    yyparse();

    /* ids.afiseazaVariabile();
    ids.afiseazaFunctii();
    ids.printUsrDefs();
    ids.afiseazaVectori(); */
    ids.exportToFile("symbol_table.txt");
    return 0;
}
