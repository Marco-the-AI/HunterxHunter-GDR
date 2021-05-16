
#include <iostream>

using namespace std;

class Personaggio
{
    public:

        string nome;

        //Attributi fisici
        int hp;
        int a_hp; //HP attuali
        int def;
        int forza;
        int exp_fisica;
        int agi;
        int intel;
        int svenuto;

        //Attributi Nen
        int MOP;  //Aura massima
        int POP;  //Aura utilizzabile prima di svenire
        int aura; //Aura attuale
        int AOP;  //Aura sprigionabile in una volta sola

        int ten;
        int zetsu;
        int ren;
        int hatsu;

        string gruppo_nen;

        //Costruttore
        Personaggio()
        {
            nome = "Sconosciuto";
            hp = a_hp = 300;
            forza = 2;
            def = 1;
            agi = 1;
            intel = 1;
            exp_fisica = 0;
            svenuto = 0;

            ten = zetsu = ren = hatsu = 0;
            MOP = aura = 1100;
            POP = MOP-100;
            AOP = 100;

            gruppo_nen = "Sconosciuto";
        }

        Personaggio(string name)
        {
            nome = name;
            hp = a_hp = 300;
            forza = 2;
            def = 1;
            agi = 1;
            intel = 1;
            exp_fisica = 0;
            svenuto = 0;

            ten = zetsu = ren = hatsu = 0;
            MOP = aura = 1100;
            POP = MOP-100;
            AOP = 100;

            gruppo_nen = "Sconosciuto";
        }

        Personaggio(string name, string classe)
        {
            nome = name;
            hp = a_hp = 300;
            forza = 2;
            def = 1;
            agi = 1;
            intel = 1;
            exp_fisica = 0;
            svenuto = 0;

            ten = zetsu = ren = hatsu = 0;
            MOP = aura = 1100;
            POP = MOP-100;
            AOP = 100;

            gruppo_nen = classe;
        }

        //Allenamento
        void meditazione()
        {
            cout << "           Ten: " << ten;
            ten += 2;
            cout << " -> " << ten << endl;

            cout << "           Zetsu: " << zetsu;
            zetsu += 2;
            cout << " -> " << zetsu << endl;

            if(aura<POP)
            {
                cout << "           Aura: " << aura;
                aura += POP/10;
                if(aura>POP)
                    aura = POP;
                cout << " -> " << aura << endl;
            }
        }

        void allenamentoFisico()
        {
            exp_fisica += 25;

            if(exp_fisica >= 100)
            {
                cout << "           HP: " << hp;
                hp += 20;
                cout << " -> " << hp << endl;

                cout << "           Forza: " << forza;
                forza++;
                cout << " -> " << forza << endl;

                cout << "           Agilita': " << agi;
                agi++;
                cout << " -> " << agi << endl;

                exp_fisica -= 100;
            }
            else
                cout << "           Esperienza fisica +25" << endl;
        }

        void allenamentoRen()
        {
            if(aura - POP/4 < 0)
            {
                cout << "           " << nome << " non puo' farlo, perche' morirebbe." << endl;
                return;
            }

            int prev = ren;

            cout << "           Ren: " << ren;
            ren += 2;
            cout << " -> " << ren << endl;

            cout << "           Aura: " << aura;
            aura -= POP/4;
            cout << " -> " << aura << endl;

            if(aura<=MOP-POP)
            {
                cout << "           " << nome << " e' svenuto." << endl;
                svenuto = 5;
            }

            if(prev/10 < ren/10)
            {
                MOP += MOP*0.8;
                POP += POP*0.8;
                AOP += AOP*0.8;
            }
        }

        //Tiro
        void tiroAgilita()
        {
            int tiro;
            cout << "           Tiro dado: ";
            cout << "\n           ";
            cin >> tiro;
            cout << "           Risultato: " << tiro+agi << endl;
        }

        void tiroIntelletto()
        {
            int tiro;
            cout << "           Tiro dado: ";
            cout << "\n           ";
            cin >> tiro;
            cout << "           Risultato: " << tiro+intel << endl;
        }

        void tiroForza()
        {
            int tiro;
            cout << "           Tiro dado: ";
            cout << "\n           ";
            cin >> tiro;
            cout << "           Risultato: " << tiro+forza << endl;
        }

        void tiroForzaRen()
        {
            int tiro;
            cout << "           Tiro dado: ";
            cout << "\n           ";
            cin >> tiro;
            cout << "           Risultato: " << tiro+forza+forza*ren/10 << endl;
            aura -= 10;

            if(aura<=MOP-POP)
            {
                cout << "           " << nome << " e' svenuto." << endl;
                svenuto = 5;
            }
        }

        void tiroDifesa()
        {
            int tiro;
            cout << "           Tiro dado: ";
            cout << "\n           ";
            cin >> tiro;
            cout << "           Risultato: " << tiro+def+ten/10 << endl;
        }

        void turno()
        {
            if(a_hp<hp)
                a_hp++;

            if(aura<POP)
                aura++;
        }
};

//Stampa dei dati del personaggio
ostream& operator<<(ostream& os, const Personaggio pg)
{
    Personaggio aux = pg;
    os << " Personaggio: " << aux.nome << ", Gruppo Nen: " << aux.gruppo_nen <<  endl << endl;
    os << "     Attributi fisici:" << endl << endl;
    os << "         Punti vita: " << aux.a_hp << "/" << aux.hp << endl;
    os << "         Forza: " << aux.forza << endl;
    os << "         Difesa: " << aux.def << endl;
    os << "         Agilita': " << aux.agi << endl;
    os << "         Intelletto: " << aux.intel << endl << endl;
    os << "     Attributi Nen:" << endl << endl;
    os << "         Aura: " << aux.aura << "/" << aux.MOP << endl;
    os << "         POP: " << aux.POP << endl;
    os << "         AOP: " << aux.AOP << endl << endl;
    os << "         Ten: " << aux.ten << endl;
    os << "         Zetsu: " << aux.zetsu << endl;
    os << "         Ren: " << aux.ren << endl;
    os << "         Hatsu: " << aux.hatsu << endl;

    return os;
}

int main()
{

    cout << "\n Qual e' il numero dei personaggi?\n ";
    int numero_pg;
    cin >> numero_pg;

    Personaggio pg [numero_pg];

    for(int i=0; i<=numero_pg; i++)
    {
        string nome{};
        if(i!=0)
            cout << "\n Nomi del personaggio numero " << i << ": ";

        getline(cin, nome);
        if(i!=0)
            pg[i-1] = Personaggio(nome);
    }

    int i = 0;
    bool azione = 1;
    while(1)
    {
        azione = 1;
        while(azione)
        {
            cout << "--------------------------------------------------------------\n";

            pg[i].turno();

            if(pg[i].svenuto)
            {
                cout << "   Turni al risveglio: " << pg[i].svenuto << endl;
                pg[i].svenuto--;

                system("PAUSE");
            }
            else
            {
                cout << endl << " Cosa vuole fare " << pg[i].nome << "?" << endl << endl;

                cout << pg[i] << endl;

                cout << "   0. Allenamento" << endl;
                cout << "   1. Attaccare" << endl;
                cout << "   2. Difendere" << endl;
                cout << "   3. Tiro agilita'" << endl;
                cout << "   4. Tiro intelletto" << endl;

                cout << "\n   ";
                int choice;
                cin >> choice;

                switch(choice)
                {
                    case 0:
                        cout << "       0. Meditazione" << endl;
                        cout << "       1. Esercizio fisico" << endl;
                        cout << "       2. Allenamento Ren" << endl;

                        int allenamento;
                        cout << "\n       ";
                        cin >> allenamento;

                        switch(allenamento)
                        {
                            case 0:
                                pg[i].meditazione();
                                break;
                            case 1:
                                pg[i].allenamentoFisico();
                                break;
                            case 2:
                                pg[i].allenamentoRen();
                                break;
                        }
                        break;

                    case 1:
                        cout << "       0. Tiro di forza" << endl;
                        cout << "       1. Tiro di forza (Ren)" << endl;

                        int scelta;
                        cout << "\n       ";
                        cin >> scelta;

                        switch(scelta)
                        {
                            case 0:
                                pg[i].tiroForza();
                                break;

                            case 1:
                                pg[i].tiroForzaRen();
                                break;
                        }

                        break;

                    case 2:
                        pg[i].tiroDifesa();
                        break;

                    case 3:
                        pg[i].tiroAgilita();
                        break;

                    case 4:
                        pg[i].tiroIntelletto();
                        break;
                }

                cout << "\n\n Un'altra azione?      SI: 1   NO: 0\n " << endl;
                cin >> azione;
                if(azione != 0 && azione != 1) //Controllo se è stato scelto correttamente 0 o 1
                        azione = 0;

            }
        }
    i++;
    if (i>=numero_pg)
        i=0;
    }
    return 0;
}
