#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

//!!! PARTEA I: Designul limbajului (ex1) - clasele Valoare, Variabila, Vector, Parametru, Functie, UserDefinedType !!!


//utilizam clasa Valoare pt a reprezenta valori de diferite tipuri (INT, FLOAT, BOOL, CHAR, STRING)
class Valoare
{
public:
    string tipul; //tipul variabilei - int, float, bool, char sau string
    int intVal; //variabile specifice pt fiecare tip de date
    float floatVal;
    bool boolVal;
    char charVal;
    string stringVal;
    bool isIntSet, isFloatSet, isBoolSet, isCharSet, isStringSet, esteConstanta = false; //ca sa verificam daca valorile corespunzatoare sunt setate sau nu - esteConstanta e ca sa vedem daca variabila e constanta
    //constructor fara parametrii
    Valoare() : isIntSet(false), isFloatSet(false), isBoolSet(false), isCharSet(false), isStringSet(false) {} //initializam variabilele booleene cu false
    //constructor cu un parametru de tip string
    Valoare(string tipul) : tipul(tipul), isIntSet(false), isFloatSet(false), isBoolSet(false), isCharSet(false), isStringSet(false) {}
    //constructor cu 2 parametri: un sir de caractere si tipul - convertim sirul la tipul corespunzator si setam variabilele corespunzatoare
    Valoare(char *valoare, string tipul)
    {
	//determinam tipul si setam corespunzator valorile
        if(tipul=="int") 
        {
            this->intVal=atoi(valoare); //convertim siru in nr intreg
            isIntSet=true;
        }
        else if(tipul=="float") 
        {
            this->floatVal=atof(valoare); //convertim siru in float
            isFloatSet=true;
        }
        else if(tipul=="bool") 
        {
            boolVal=(string(valoare)=="true");
            isBoolSet=true;
        }
        else if (tipul == "char") {
            this->charVal = valoare[0];
            isCharSet = true;
        }
        else if (tipul == "string") {
            this->stringVal = valoare;
            isStringSet = true;
        }
        this->tipul = tipul;
    }
};


class Variabila //gestioneaza variabile: nume, valoare, unde sunt definite
{
public:
    std::string nume; //numele variabilei
    Valoare val; //o instanta a clasei Valoare care repr valoarea variabilei
    string context; //indica in ce context (functie, clasa) e definita variabila 
    //constructor - primeste numele si valoarea variabilei si le atribuie membrilor corespunzatori
    Variabila(const std::string &nume, const Valoare &val) : nume(nume), val(val) {}
    //returneaza valoarea variabilei
    Valoare Eval()
    { return this->val;}
    //returneaza tipul variabilei
    string TypeOf()
    {
        if (val.isIntSet) 
        {
            val.tipul = "int";
            return "int";
        }
        else if (val.isFloatSet) 
        {
            val.tipul = "float";
            return "float";
        }
        else if (val.isBoolSet) 
        {
            val.tipul = "bool";
            return "bool";
        }
        else if (val.isCharSet) 
        {
            val.tipul = "char";
            return "char";
        }
        else if (val.isStringSet) 
        {
            val.tipul = "string";
            return "string";
        }
    }
};

class UserDefinedType //ca sa reprezentam tipuri de date definite de utilizator
{
public:
    string nume;
    UserDefinedType(const string &nume) : nume(nume) {} //constructor
};

class Vector //implementarea unui vector, lucru cu arrays
{
public:
    string nume;
    string tipul;
    string context;
    int capacitate= 0; //nr maxim de elemente pe care le poate contine
    int contor = 0; //indicele curent al vectorului, indica urmatoarea pozitie disponibila pt adaugarea unui element

    vector<Valoare> valvec; //valorile stocate in vector
    Vector(const string &nume, int capacitate, string tipul) : nume(nume), capacitate(capacitate), tipul(tipul) {} //constructor

    void push(Valoare val) //adaugam o valoare la sfarsitul vectorului
    {
        contor++;
        if (contor <= capacitate) //verificam daca a depasit capacitatea maxima
            valvec.push_back(val); //daca nu
        else
            printf("Segmentation fault."); //daca da
            return;
    }

    void adauga(int ind, Valoare val) //adaugam o valoare la o anumita pozitie "ind" in vector - relizam extinderea vectorului daca e necesar
    {
        if (ind < 0 || ind > capacitate)
        {
            printf("Indexul nu respecta limitele.\n");
            return;
        }
        else if (ind > contor)
        {
            for (int i = 0; i < ind; i++)
            {
                valvec.resize(ind + 1, Valoare());
            }
            valvec.at(ind) = val;
            contor = ind;
        }
        else if (contor == ind)
        {
            valvec.push_back(val);
            contor++;
        }
        else
            valvec.at(ind) = val;
    }

    Valoare obtineValoare(int ind) //returneaza valoarea de la pozitia specificata "ind" - verificam daca indicele este in limitele vectorului 
    {

        if (ind < 0 || ind > capacitate || ind > contor)
        {
            printf("Indexul nu respecta limitele.\n");
            return Valoare();
        }
        else
            return valvec.at(ind);
    }
};

class Parametru //retine informatii despre parametrii functiilor
{
public:
    string nume;
    string tipul;
    bool esteConstanta = false; //specifica daca parametrul e constant sau nu
    Parametru(const string &nume, const string &tipul) : nume(nume), tipul(tipul) {} //constructor - primeste numele si tipul parametrului si ii atribuie membrilor corespunzatori
};

class Functie //ca sa reprezentam functiile (nume, tip, context, parametrii)
{
public:
    string nume; 
    string returnType; //tipul returnat de functie
    string context; 
    vector<Parametru> parametri; //vector de obiecte de tip Parametru
    Functie(const string &nume, const string &returnType, const string &context) : nume(nume), returnType(returnType), context(context) {} //constructor
};

//!!! PARTEA 2: Tabela de simboluri (ex2) !!!

class IdList // !! stocam aici informatii despre variabile, functii, tipuri definite de utilizatori si vectori - verifica existenta lor
{
    //vectori pentru stocarea informatiilor despre variabile, functii, tipuri definite de utilizator si vectori
    vector<Variabila> variabile;
    vector<Functie> functii;
    vector<UserDefinedType> usrdefs;
    vector<Vector> vectori;
    

 public: //metode pentru verificarea existentei diferitelor elemente in lista
    bool existaClasa(const char *nume) //verificam daca exista o clasa cu numele specificat
    {
        for (const auto &usrdef : usrdefs)
            if (usrdef.nume == nume)
                return true;
        return false;
    }
    bool existaVariabila(const char *tipul, string context)  //verificam daca exista o variabila cu tipul si contextul specificat
    {
        for (const auto &var : variabile)
            if (var.val.tipul == tipul && var.context == context)
                return true;
        return false;
    }
    int existaVector(const char *nume)   //verificam daca exista un vector cu numele specificat
    {
        for (const auto &vector : vectori)
            if (vector.nume == nume)
                return 1;
        return 0;
    }
    
    ///functii care contribuie pt Partea 3 (asigura conformitatea tipurilor si unicitatea numelor)
    
    int existaFunctia(const char *nume, string context) //verificam daca exista o functie cu numele si contextul specificat
    {
        for (const auto &vector : vectori)
            if (vector.nume == nume && vector.context == context)
                return 3; //acelasi vector in acelasi context/scop
        for (const auto &var : variabile)
            if (var.nume == nume && var.context == context)
                return 3; //acelasi nume de variabila in acelasi context
        for (const auto &usrdef : usrdefs)
            if (usrdef.nume == nume && usrdef.nume == context)
                return 2; //returnam tipul specificat pt constructorul invalid
        for (const auto &func : functii)
            if (func.nume == nume && func.context == context)
                return 1; //acelasi nume de functie in acelasi context
        return 0;
    }
    bool exista(const char *nume) //verificam daca exista un element (variabila, functie, tip definit de utilizator sau vector) cu numele specificat
    {
        for (const auto &var : variabile)
            if (var.nume == nume)
                return true;
        for (const auto &func : functii)
            if (func.nume == nume)
                return true;
        for (const auto &usrdef : usrdefs)
            if (usrdef.nume == nume)
                return true;
        for (const auto &vector : vectori)
            if (vector.nume == nume)
                return true;
        return false;
    }
    int exista(const char *nume, string context)  //verificam daca exista un element (variabila, functie, tip definit de utilizator sau array) cu numele si contextul specificat
    {
        for (const auto &var : variabile)
            if (var.nume == nume && var.context == context)
                return 1; //acelasi nume de variabila pt acelasi context
        for (const auto &vector : vectori)
            if (vector.nume == nume && vector.context == context)
                return 1; //acelasi nume de vector acelasi context 
        for (const auto &func : functii)
            if (func.nume == nume && func.context == context)
                return 2; //acelasi nume de functie pt ac context
        for (const auto &usrdef : usrdefs)
            if (usrdef.nume == nume)
                return 3; //acelasi nume definit de user
        return 0;
    }

    Variabila &obtineVariabila(const char *nume) //obtinem o referinta la o variabila cu numele specificat
    {
        for (auto &var : variabile)
            if (var.nume == nume)
                return var;
        throw std::runtime_error("Variabila nu a fost gasita: " + std::string(nume));
    }

    Functie &obtineFunctie(const char *nume) //obtinem o referinta la o functie cu numele specificat
    {
        for (auto &func : functii)
            if (func.nume == nume)
                return func;
        throw std::runtime_error("Functia nu a fost gasita: " + std::string(nume));
    }

    UserDefinedType &getUDT(const char *nume) //obtinem o referinta la un tip definit de utilizator cu numele specificat
    {
        for (auto &udt : usrdefs)
            if (udt.nume == nume)
                return udt;
        throw std::runtime_error("Clasa nu a fost gasita: " + std::string(nume));
    }

    Vector &obtineVector(const char *nume)  //obtinem o referinta la un vector cu numele specificat
    {
        for (auto &vector : vectori)
            if (vector.nume == nume)
                return vector;
        throw std::runtime_error("Vectorul nu a fost gasit: " + std::string(nume));
    }
    //metode pt adaugarea elementelor in lista
    void adaugaVar(const Variabila &var)
    { variabile.push_back(var); }
    void adaugaFunc(const Functie &func)
    { functii.push_back(func);  }
    void adaugaUsrDef(const UserDefinedType &usrdef)
    { usrdefs.push_back(usrdef); }
    void adaugaVec(const Vector &vector)
    { vectori.push_back(vector); }
    
    void afiseazaVariabile()
    {
        if (variabile.empty()) {
            std::cout << "Nicio variabila pe display." << std::endl;
            return;
        }
        
        std::cout << "Lista variabile:" << std::endl;
        for (const auto &var : variabile)
        {
            std::cout << "Nume: " << var.nume << ", Tipul: " << var.val.tipul << ", Context: " << var.context;

            if (var.val.isIntSet)
                std::cout << ", Int Valoare: " << var.val.intVal;
            if (var.val.isFloatSet)
                std::cout << ", Float Valoare: " << var.val.floatVal;
            if (var.val.isBoolSet)
                std::cout << ", Bool Valoare: " << (var.val.boolVal ? "true" : "false");
            if (var.val.isCharSet)
                std::cout << ", Char Valoare: " << var.val.charVal;
            if (var.val.isStringSet)
                std::cout << ", String Valoare: " << var.val.stringVal;

            std::cout << ", e constanta?:";
            if (var.val.esteConstanta)
                std::cout << " Constanta";
            else
                std::cout << " Nu e constanta";

            std::cout << std::endl;
        }
    }

    void afiseazaFunctii()
    {
        if (functii.empty())
        {
            std::cout << "Nicio functie pe display." << std::endl;
            return;
        }

        std::cout << "Lista Functii:" << std::endl;
        for (const auto &func : functii)
        {
            std::cout << "Nume: " << func.nume << ", Return Tipul: " << func.returnType << ", Context: " << func.context << std::endl;
            if (!func.parametri.empty())
            {
                std::cout << "\tParametrii: " << std::endl;
                for (const auto &param : func.parametri)
                    std::cout << "\t\tNume: " << param.nume << ", Tipul: " << param.tipul;
                std::cout << ", e constanta?: ";
                if (func.parametri.back().esteConstanta)
                    std::cout << "Constanta";
                else
                    std::cout << "Nu e constanta";
                cout << std::endl;
            }
        }
    }

    void printUsrDefs()
    {
        if (usrdefs.empty())
        {
            std::cout << "Niciun user nu a definit tipuri pe display." << std::endl;
            return;
        }

        std::cout << "Lista tipurilor definite de user:" << std::endl;
        for (const auto &usrdef : usrdefs)
            std::cout << "Nume: " << usrdef.nume << std::endl;
    }

    void afiseazaVectori()
    {
        if (vectori.empty())
        {
            std::cout << "Niciun vector pe display." << std::endl;
            return;
        }

        std::cout << "Lista vectorilor:" << std::endl;
        for (const auto &vector : vectori)
        {
            std::cout << "Nume: " << vector.nume << ", Tipul: " << vector.tipul << ", Capacitatea: " << vector.capacitate << ", Context: " << vector.context << std::endl;
            std::cout << "\tElemente: ";
            for (auto &element : vector.valvec)
            {
                if (element.tipul == "char")
                    cout << element.charVal << " ";
                else if (element.tipul == "float")
                    cout << element.floatVal << " ";
                else if (element.tipul == "bool")
                    cout << element.boolVal << " ";
                else if (element.tipul == "int")
                    cout << element.intVal << " ";
            }
            std::cout << std::endl;
        }
    }

    void exportToFile(std::string fileName) //exportam informatiile din lista in fisierul specificat
    {
        std::ofstream file(fileName);
        if (file.is_open())
        {
            file << "SYMBOL TABLE\n\n";
            file << "Lista variabilelor:\n";
            for (const auto &var : variabile)
            {
                file << "Nume: " << var.nume << ", Tipul: " << var.val.tipul << ", Context: " << var.context;
                if (var.val.isIntSet)
                    file << ", Valoare: " << var.val.intVal;
                if (var.val.isFloatSet)
                    file << ", Valoare: " << var.val.floatVal;
                if (var.val.isBoolSet)
                    file << ", Valoare: " << (var.val.boolVal ? "true" : "false");
                if (var.val.isCharSet)
                    file << ", Valoare: " << var.val.charVal;
                if (var.val.isStringSet)
                    file << ", String Valoare: " << var.val.stringVal;
                file << ", E Constanta?: " << (var.val.esteConstanta ? "CONSTANTA" : "NU E CONSTANTA") << "\n";
            }

            file << "\nLista de vectori:\n";
            for (const auto &vector : vectori)
            {
                file << "Nume: " << vector.nume << ", Tipul: " << vector.tipul << ", Capacitatea: " << vector.capacitate << ", Context: " << vector.context;
                if (!vector.valvec.empty())
                {
                    file << "\n\tElemente: ";
                    for (const auto &element : vector.valvec)
                    {
                        if (element.tipul == "char")
                            file << element.charVal << " ";
                        else if (element.tipul == "float")
                            file << element.floatVal << " ";
                        else if (element.tipul == "bool")
                            file << element.boolVal << " ";
                        else if (element.tipul == "int")
                            file << element.intVal << " ";
                    }
                    file << "\n";
                }
                else
                    file << ", Elemente: Niciunu\n";
            }

            file << "\nLista Functii:\n";
            for (const auto &func : functii)
            {
                file << "Nume: " << func.nume << ", Return Tipul: " << func.returnType << ", Context: " << func.context << "\n\tParametrii:\n";
                for (const auto &param : func.parametri)
                    file << "\t\tNume: " << param.nume << ", Tipul: " << param.tipul << ", E Constanta?: " << (param.esteConstanta ? "CONSTANT" : "NU E CONSTANT") << "\n";
            }

            file << "\nLista tipurilor definite de user:\n";
            for (const auto &typeName : usrdefs)
                file << "Nume: " << typeName.nume << "\n";
            file.close();
        }
        else
            std::cerr << "Unable to open file for writing.\n";
    }
    ~IdList() {} //destructor pentru eliberarea resurselor
};

//!!! PARTEA 3: Analiza semantica (ex3) MAI SUS, parte din clasele Variabila, Functie, Vector, IdList !!!    


//!!! PARTEA 4: Evaluarea expresiilor si tipurilor (implementarea AST) !!!    
//expresii aritmetice si boooleene

class AST
{

public:
    string tipul = ""; //tipul nodului
    Valoare val;
    string root; //radacina nodului
    AST *left; //fiu stanga
    AST *right; //fiu dreapta 

    AST(AST *left, string root, AST *right) : root(root), left(left), right(right) {} //constructor pentru un nod al arborelui cu 2 fii si un nod radacina specificat

    AST(Valoare *val) : val(*val) //constructor pentru un nod al arborelui cu o valoare specificata - pointer la Valoare
    {
        if (val->tipul == "int")
            tipul = "int";
        else if (val->tipul == "float")
            tipul = "float";
        else if (val->tipul == "bool")
            tipul = "bool";
        else if (val->tipul == "char")
            tipul = "char";
        else if (val->tipul == "string")
            tipul = "string";
    }
    AST(Valoare val) : val(val) //constructor pentru un nod al arborelui cu o valoare specificata - primeste direct un obiect de tip Valoare
    {
        if (val.tipul == "int")
            tipul = "int";
        else if (val.tipul == "float")
            tipul = "float";
        else if (val.tipul == "bool")
            tipul = "bool";
        else if (val.tipul == "char")
            tipul = "char";
        else if (val.tipul == "string")
            tipul = "string";
    }

    Valoare Eval() //evaluam nodul curent in functie de operatia specificata de radacina si valorile fii
    {

        if (root.empty())
            return val;
        else if (left && right && left->TypeOf() == right->TypeOf())
        {

            Valoare leftResult = left->Eval();
            Valoare rightResult = right->Eval();
            Valoare result;

            if (left->tipul == "int")
            {

                result.tipul = "int";
                result.isIntSet = true;
		//efectuam operatii (in functie de ce ne zice radacina) intre valorile int ale fiilor
                if (root == "+")
                {
                    result.intVal = leftResult.intVal + rightResult.intVal;
                    return result;
                }
                else if (root == "-")
                {
                    result.intVal = leftResult.intVal - rightResult.intVal;
                    return result;
                }
                else if (root == "*")
                {
                    result.intVal = leftResult.intVal * rightResult.intVal;
                    return result;
                }
                else if (root == "/")
                {
                    result.intVal = leftResult.intVal / rightResult.intVal;
                    return result;
                }
                else if (root == "%")
                {
                    result.intVal = leftResult.intVal % rightResult.intVal;
                    return result;
                }
		 //setam tipul rezultatului ca bool pentru operatiile de comparare
                result.tipul = "bool";
                result.isIntSet = false;
                result.isBoolSet = true;
		//efectuam operatii de comparare intre valorile int ale fiilor
                if (root == "gt")
                    result.boolVal = leftResult.intVal > rightResult.intVal;
                else if (root == "lt")
                    result.boolVal = leftResult.intVal < rightResult.intVal;
                else if (root == "geq")
                    result.boolVal = leftResult.intVal >= rightResult.intVal;
                else if (root == "leq")
                    result.boolVal = leftResult.intVal <= rightResult.intVal;
                else if (root == "eq")
                    result.boolVal = leftResult.intVal == rightResult.intVal;
                else if (root == "neq")
                    result.boolVal = leftResult.intVal != rightResult.intVal;

                return result;
            }
            else if (left->tipul == "float") //acelasi lucru facem si pt float
            {

                result.tipul = "float";
                result.isFloatSet = true;

                if(root=="+")
                {
                    result.floatVal=leftResult.floatVal+rightResult.floatVal;
                    return result;
                }
                else if (root == "-")
                {
                    result.floatVal = leftResult.floatVal - rightResult.floatVal;
                    return result;
                }
                else if (root == "*")
                {
                    result.floatVal = leftResult.floatVal * rightResult.floatVal;
                    return result;
                }
                else if (root == "/")
                {
                    result.floatVal = leftResult.floatVal / rightResult.floatVal;
                    return result;
                }

                result.tipul = "bool";
                result.isFloatSet = false;
                result.isBoolSet = true;

                if (root == "gt")
                    result.boolVal = leftResult.floatVal > rightResult.floatVal;
                else if (root == "lt")
                    result.boolVal = leftResult.floatVal < rightResult.floatVal;
                else if (root == "geq")
                    result.boolVal = leftResult.floatVal >= rightResult.floatVal;
                else if (root == "leq")
                    result.boolVal = leftResult.floatVal <= rightResult.floatVal;
                else if (root == "eq")
                    result.boolVal = leftResult.floatVal == rightResult.floatVal;
                else if (root == "neq")
                    result.boolVal = leftResult.floatVal != rightResult.floatVal;
                return result;
            }
            else if (left->tipul == "bool") //pentru bool
            {

                result.tipul = "bool";
                result.isBoolSet = true;

                if (root == "or")
                    result.boolVal = leftResult.boolVal || rightResult.boolVal;
                else if (root == "and")
                    result.boolVal = leftResult.boolVal && rightResult.boolVal;
                else if (root == "gt")
                    result.boolVal = leftResult.boolVal > rightResult.boolVal;
                else if (root == "lt")
                    result.boolVal = leftResult.boolVal < rightResult.boolVal;
                else if (root == "geq")
                    result.boolVal = leftResult.boolVal >= rightResult.boolVal;
                else if (root == "leq")
                    result.boolVal = leftResult.boolVal <= rightResult.boolVal;
                else if (root == "eq")
                    result.boolVal = leftResult.boolVal == rightResult.boolVal;
                else if (root == "neq")
                    result.boolVal = leftResult.boolVal != rightResult.boolVal;
            }

            return result;
        }
        else if (left && root == "not") //pt operatia de negare logica
        {
            Valoare result;
            result.isBoolSet = true;
            result.boolVal = !left->Eval().boolVal;
            result.tipul = "bool";
            return result;
        }
        else if (left && root == "-") //negare aritmetica 
        {
            Valoare result;
            if (left->tipul == "float")
            {
                result.isFloatSet = true;
                result.floatVal = -(left->Eval().floatVal);
                result.tipul = "int";
            }
            else
            {
                result.isIntSet = true;
                result.intVal = -(left->Eval().intVal);
                result.tipul = "int";
            }
            return result;
        }
        else
            return val;  //daca radacina este vida, returnam valoarea nodului
    }

    string TypeOf() //returnam tipul nodului curent
    {
        if (!root.empty())
        {
            if (left && right)
            {
                string leftType = left->TypeOf();
                string rightType = right->TypeOf();

                if (!leftType.empty() && !rightType.empty())
                {
                    if (leftType == rightType)
                    {   //setam tipul nodului curent in functie de operatia radacinii
                        if (root == "+" || root == "-" || root == "/" || root == "*" || root == "%")
                        {
                            this->tipul = leftType;
                            return leftType;
                        }
                        else
                            return "bool";  //pentru operatiile logice, tipul este bool
                    }
                    else
                    {  //afisam o eroare daca tipurile fiilor nu coincid
                        cout << "Different types: operation " << this->root << " between " << leftType << " and " << rightType << endl;
                        return "Error";
                    }
                }
            }
            else
                return left->TypeOf(); //daca exista doar un fiu, returnam tipul fiului
        }

        return tipul;   //daca radacina este vida, returnam tipul nodului curent
    }

    void printAst() //afisam arborele
    {

        if (left != NULL) //parcurgem arborele in ordine (stanga - radacina - dreapta)
            this->left->printAst();
        //afisam informatia din nodul curent
        if (!root.empty())
            cout << root << " "; //afisam informatia din nodul curent
        else
        {   //daca radacina este vida, afisam valoarea nodului
            if (val.isIntSet)
                cout << val.intVal << " ";
            else if (val.isFloatSet)
                cout << val.floatVal << " ";
            else if (val.isBoolSet)
                cout << val.boolVal << " ";
            else if (val.isCharSet)
                cout << val.charVal << " ";
            else if (val.isStringSet)
                cout << val.stringVal << " ";
        }
        if (right != NULL) //parcurgem fiul drept
            this->right->printAst();
    }
};
