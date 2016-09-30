#include<iostream>
#include<fstream>
using namespace std;

class Autovehicul
{
private:
	char* marca;
	char* model;
	float viteza;
	float pret;
	static float nrAutovehicule;
	const int id;

public:

	//constructor implicit

	Autovehicul() :id(1)
	{
		this->marca=new char[strlen("Dacia")+1];
		strcpy(marca, "Dacia ");
		this->model=new char[strlen("Sandero")+1];
		strcpy(model, " Sandero");
		this->viteza = 90;
		this->pret = 10000;
		nrAutovehicule++;
	}

	//constructor explicit

	Autovehicul(char* marca, char* model, float viteza, float pret, int id_nou) :id(id_nou)
	{
		this->marca=new char[strlen(marca)+1];
		strcpy(this->marca, marca);
		this->model=new char[strlen(model)+1];
		strcpy(this->model, model);
		this->viteza = viteza;
		this->pret = pret;
		nrAutovehicule++;
	}

	//constructor de copiere

	Autovehicul(const Autovehicul &a) :id(a.id)
	{
		this->marca=new char[strlen(a.marca)+1];
		strcpy(this->marca, a.marca);
		this->model=new char[strlen(a.model)+1];
		strcpy(this->model, a.model);
		this->viteza = a.viteza;
		this->pret = a.pret;

	}

	//destructor
	~Autovehicul()
	{
		delete[] marca;
		delete[] model;
		nrAutovehicule--;
	}


	//operator =

	Autovehicul operator=(const Autovehicul &a)
	{
		delete[] a.marca;
		delete[] a.model;
		this->marca=new char[strlen(a.marca)+1];
		strcpy(this->marca, a.marca);
		this->model=new char[strlen(a.model)+1];
		strcpy(this->model, a.model);
		this->viteza = a.viteza;
		this->pret = a.pret;
		return *this;
	}

	char *getMarca()
	{
		return marca;
	}

	char *getModel()
	{
		return model;
	}

	float getViteza()
	{
		return viteza;
	}

	float getPret()
	{
		return pret;
	}


	static float getnrAutovehicule()
	{
		return nrAutovehicule;
	}

	int getId()
	{
		return id;
	}



	void setMarca(char *marca)
	{
		if (marca != NULL)
			delete[] marca;
			this->marca=marca;
			strcpy(this->marca, marca);
	}

	void setModel(char *model)
	{
		if (model != NULL)
			delete[] model;
			this->model=model;
			strcpy(this->model, model);
	}

	void setViteza(float viteza)

	{
		this->viteza = viteza;
	}

	void setPret(float pret)
	{
		this->pret = pret;
	}
	//operator ()
	operator int()
	{
		return pret;
	}


	friend ostream& operator<<(ostream&, Autovehicul &);
	friend istream& operator>>(istream&, Autovehicul &);
};
float Autovehicul::nrAutovehicule = 0;
ostream &operator<<(ostream& o, Autovehicul& a)
{
	o << "Masina are marca " << a.marca << " si modelul " << a.model << endl;
	o << "Pretul masinii este de : " << a.pret << endl;
	return o;
}
istream &operator>>(istream& i, Autovehicul& a)
{
	
	char nume[100];
	delete[] a.marca;
	cout << "marca: ";
	i >> nume;
	a.marca=new char[strlen(nume)+1];
	strcpy(a.marca,nume);
	i.ignore();
	char aux[100];
	delete[] a .model;
	cout << "model";
	i >> aux;
	a.model=new char[strlen(aux)+1];
	strcpy(a.model,aux);
	i.ignore();
	cout << "pret:";
	i >> a.pret;
	cout << "viteza";
	i >> a.viteza;
	return i;
}

class Motor
{
private:
	char* tip; //diesel , benzina, electric
	float capacitate_cilindrica;
	int putere;
	int teste; //de cate ori s-a testat consumul
	float* consum; //ce rezultate au iesit in urma testelor

public:
	//constructor implicit
	
		Motor()
		{
			this->tip = new char[strlen("Benzina") + 1];
			strcpy(this->tip, "Benzina");
			this->capacitate_cilindrica = 2.5;
			this->putere = 132;
			this->teste = 5;
			this->consum = new float[this->teste];
			this->consum[0] = 7;
			this->consum[1] = 8;
			this->consum[2] = 4;
			this->consum[3] = 5;
			this->consum[4] = 6;
		}

		//consrutor explicit

		Motor(char* tip, float capacitate_cilindrica, int putere, int teste, float* consum)
		{
			this->tip = new char[strlen(tip) + 1];
			strcpy(this->tip, tip);
			this->capacitate_cilindrica = capacitate_cilindrica;
			this->putere = putere;
			this->teste = teste;
			this->consum = new float[teste];
			{for (int i = 0;i < teste;i++)
				this->consum[i] = consum[i];
			}
		}

		//constructor de copiere

		Motor(const Motor& m)
		{
			if (m.tip)
			{
				this->tip = new char[strlen(m.tip) + 1];
				strcpy(this->tip, m.tip);
			}
			else
			{
				tip = new char[strlen("nedefinit") + 1];
				strcpy(tip, "nedefinit");
			}
			this->capacitate_cilindrica = m.capacitate_cilindrica;
			this->putere = m.putere;
			if (m.consum)
			{
				this->teste = m.teste;
				this->consum = new float[m.teste];
				for (int i = 0;i < m.teste;i++)
				{
					this->consum[i] = m.consum[i];
				}
			}
			else
			{
				this->teste = 5;
				this->consum = new float[this->teste];
				this->consum[0] = 7;
				this->consum[1] = 8;
				this->consum[2] = 4;
				this->consum[3] = 5;
				this->consum[4] = 6;
			}
		}

		//functia care calculeaza consumul mediu

		float consum_mediu()
		{
			float consumTotal = 0;
			for (int i = 0;i<this->teste;i++)
				consumTotal = consumTotal + this->consum[i];
			return consumTotal / this->teste;
		}

		//destructor

		~Motor()
		{
			if (tip)
			{
				delete[] tip;
			}
			if (consum)
			{
				delete[] consum;
			}
		}

		//operator egal

		Motor operator=(const Motor& m)
		{
			if (m.tip != NULL)
			{
				delete[] tip;
				this->tip = new char[strlen(m.tip) + 1];
				strcpy(this->tip, m.tip);
			}
			else
			{
				tip = new char[strlen("nedefinit") + 1];
				strcpy(tip, "nedefinit");
			}
			this->capacitate_cilindrica = m.capacitate_cilindrica;
			this->putere = m.putere;
			if (m.consum)
			{
				delete[] consum;
				this->teste = m.teste;
				this->consum = new float[m.teste];
				for (int i = 0;i < m.teste;i++)
				{
					this->consum[i] = m.consum[i];
				}
			}
			else
			{
				this->teste = 5;
				this->consum = new float[this->teste];
				this->consum[0] = 7;
				this->consum[1] = 8;
				this->consum[2] = 4;
				this->consum[3] = 5;
				this->consum[4] = 6;
			}
			return *this;
		}

		char *getTip()
		{
			return tip;
		}

		float getCapacitate_cilindrica()
		{
			return capacitate_cilindrica;
		}

		int getPutere()
		{
			return putere;
		}

		int getTeste()
		{
			return teste;
		}

		float* getConsum()
		{
			return consum;
		}

		void setTip(char* tip)
		{
			if (tip != NULL)
			{
				delete[] this->tip;
				this->tip = new char[strlen(tip) + 1];
				strcpy(this->tip, tip);
			}
			else
			{
				tip = new char[strlen(" ") + 1];
				strcpy(tip, " ");
			}
		}

		void setCapacitate_cilindrica(float capacitate_cilindrica)
		{
			this->capacitate_cilindrica = capacitate_cilindrica;
		}

		void setPutere(float putere)
		{
			this->putere = putere;
		}

		void setTeste(int teste)
		{
			this->teste = teste;
		}

		void setConsum(float* consum)
		{
			if (consum != NULL)
			{
				delete[] this->consum;
				this->consum = new float[teste];
				for (int i = 0; i<teste; i++)
					this->consum[i] = consum[i];
			}
		}

		float &operator[](int index)//operator index
		{
			if (index >= 0 && index < this->teste)
				return this->consum[index];
			else
				throw "indexul nu este intre parametri";
		}

		//operator ++ pre-incrementare
		Motor operator++()
		{
			this->putere += 50;
			return *this;
		}


		friend ostream &operator<< (ostream&, Motor&); //functia friend pentru operatorul <<
		friend istream &operator >> (istream&, Motor&);//functia friend pentru operatorul >>
	};
	ostream &operator<< (ostream& o, Motor& m)//operatorul <<
	{
		o << "tipul motorului: " << m.tip << endl;
		o << "capacitatea motorului: " << m.capacitate_cilindrica << endl;
		o << "puterea motorului: " << m.putere << endl;
		o << "teste consum motor: " << m.teste << endl;
		o << "consumurile rezultate in urma testarii: ";
		for (int i = 0;i < m.teste;i++)
			o << m.consum[i] << " ";
		o << endl;
		return o;
	}
	istream &operator >> (istream& in, Motor& m)	//operatorul >>
	{
		delete[]m.tip;
		char aux[20];
		cout << "Motorul este de tipul: ";
		in >> aux;
		m.tip = new char[strlen(aux) + 1];
		strcpy(m.tip, aux);
		cout << "capacitatea cilindrica a motorului: ";
		in >> m.capacitate_cilindrica;
		cout << "puterea motorului: ";
		in >> m.putere;
		cout << "tastarile consumului: ";
		in >> m.teste;
		cout << "consumurile rezultate sunt: ";
		m.consum = new float[m.teste];
		for (int i = 0;i < m.teste;i++)
			in >> m.consum[i];
		return in;
	}

	class Sofer
	{
	private:
		char* nume;
		long long cnp;
		float salariu;
		float distantaParcursaPeSaptamana[7];//cati  km a parcurs soferul cu masina in fiecare zi,timp de o saptamana

	public:

		char* getNume()
		{
			return nume;
		}

		float getSalariu()
		{
			return salariu;
		}

		long long getCnp()
		{
			return cnp;
		}

		float *getDistantaParcursaPeSaptamana()
		{
			return distantaParcursaPeSaptamana;
		}

		void setNume(char* nume)
		{
			if (nume != NULL)
			{
				delete[]this->nume;
				this->nume = new char[strlen(nume) + 1];
				strcpy(this->nume, nume);
			}
			else
			{
				this->nume = new char[strlen("Xeni") + 1];
				strcpy(this->nume, "Xeni");
			}
		}

		void setSalariu(float salariu)
		{
			this->salariu = salariu;
		}

		void setCnp(long long cnp)
		{
			this->cnp = cnp;
		}

		void setDistantaParcursaPeSaptamana(float *distantaParcursaPeSaptamana)
		{
			for (int i = 0;i<7;i++)
				this->distantaParcursaPeSaptamana[i] = distantaParcursaPeSaptamana[i];
		}


		//constructor implicit

		Sofer()
		{
			this->nume = new char[strlen("Xeni") + 1];
			strcpy(this->nume, "Xeni");
			this->salariu = 10000;
			this->cnp = 2230819933249;
			distantaParcursaPeSaptamana[0] = 1.4;
			distantaParcursaPeSaptamana[1] = 2;
			distantaParcursaPeSaptamana[2] = 3.1;
			distantaParcursaPeSaptamana[3] = 1.8;
			distantaParcursaPeSaptamana[4] = 15.3;
			distantaParcursaPeSaptamana[5] = 8.4;
			distantaParcursaPeSaptamana[6] = 25.6;

		}

		//constructor expplicit

		Sofer(char* nume, long long cnp, float salariu, float *distantaParcursaPeSaptamana)
		{
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
			this->cnp = cnp;
			this->salariu = salariu;
			for (int i = 0;i<7;i++)
				this->distantaParcursaPeSaptamana[i] = distantaParcursaPeSaptamana[i];
		}

		//destructor

		~Sofer()
		{
			if (nume)
				delete[] nume;
		}

		//constructor de copiere

		Sofer(const Sofer& s)
		{

			this->nume = new char[strlen(s.nume) + 1];
			strcpy(this->nume, s.nume);
			this->cnp = s.cnp;
			this->salariu = s.salariu;
			for (int i = 0;i<7;i++)
				this->distantaParcursaPeSaptamana[i] = s.distantaParcursaPeSaptamana[i];
		}

		//operatorul =

		Sofer operator=(const Sofer& s)
		{
			if (nume != NULL)
			{
				delete[] nume;
				this->nume = new char[strlen(s.nume) + 1];
				strcpy(this->nume, s.nume);
				this->cnp = s.cnp;
				this->salariu = s.salariu;
				for (int i = 0;i<7;i++)
					this->distantaParcursaPeSaptamana[i] = s.distantaParcursaPeSaptamana[i];
				return *this;
			}
		}
		Sofer operator+(Sofer temp) //operatorul + 
		{
			Sofer aux = *this;
			aux.salariu += this->salariu;
			return aux;
		}

		Sofer operator-(Sofer temp) //operatorul -
		{
			Sofer aux = *this;
			aux.salariu = aux.salariu - this->salariu;
			return aux;
		}

		Sofer operator*(Sofer temp) //operatorul *
		{
			Sofer aux = *this;
			aux.salariu *= this->salariu;
			return aux;
		}
		Sofer operator/(Sofer temp) //operatorul /
		{
			Sofer aux = *this;
			aux.salariu /= this->salariu;
			return aux;
		}
	    Sofer operator++(int)  //opretaroul++ post-incrementare
		{
			Sofer aux = *this;
			this->salariu += 100;
			return aux;

		}

		Sofer operator+=(Sofer temp) //operatorul +=
		{
			Sofer aux = *this;
			aux.salariu += this->salariu;
			return aux;
		}

		Sofer operator-=(Sofer temp) //operatorul -=
		{
			Sofer aux = *this;
			aux.salariu = aux.salariu - this->salariu;
			return aux;
		}

		Sofer operator*=(Sofer temp) //operatorul *=
		{
			Sofer aux = *this;
			aux.salariu *= this->salariu;
			return aux;
		}
		friend ostream &operator << (ostream&o, Sofer& s);//functia friend pentru operatorul <<
		friend istream &operator >>(istream&i, Sofer& s);//functia friend pentru operatorul >>

	};
	ostream &operator <<(ostream &o, Sofer& s) //operatorul <<
	{
		o << "Numele soferului este: " << s.nume << endl;
		o << "Salariul soferului este: " << s.salariu << endl;
		o << "Cnp-ul soferului este: " << s.cnp << endl;
		cout << "Distanta in km parcursa pe saptamana de un sofer in fiecare zi,timp de o saptamana este: ";
		for (int i = 0;i < 7;i++)
			o << s.distantaParcursaPeSaptamana[i] << " ";
		o << endl;
		return o;
	}
	istream &operator >>(istream &in, Sofer &s) //operatorul >>
	{
		delete[] s.nume;
		char aux[30];
		cout << "Introduceti numele soferului: ";
		in >> aux;
		s.nume = new char[strlen(aux) + 1];
		strcpy(s.nume, aux);
		cout << "Introduceti salariul soferului: ";
		in >> s.salariu;
		cout << "Introduceti cnp-ul soferului: ";
		in >> s.cnp;
		cout << "Introduceti distanta in km parcursa pe saptamana de un sofer in fiecare zi,timp de o saptamana";
		for (int i = 0;i < 7;i++)
			in >> s.distantaParcursaPeSaptamana[i];
		return in;

	}

	class Cursa
	{
	private:
		char *denumireCursa;
		char *tip;//nationala,internationaa
		const int idCursa;
		double lungimeCursa;

	public:

		//constructor implicit

		Cursa() :idCursa(1)
		{
			this->denumireCursa = new char[strlen("Bucuresti-Targu-Jiu") + 1];
			strcpy(this->denumireCursa, "Bucuresti-Targu-Jiu");
			this->tip = new char[strlen("nationala") + 1];
			strcpy(this->tip, tip);
			this->lungimeCursa = 340;
		}

		//constructor explicit

		Cursa(char *denumireCursa, char* tip, double lungimeCursa, int idCursa_nou) :idCursa(idCursa_nou)
		{
			this->denumireCursa = new char[strlen(denumireCursa) + 1];
			strcpy(this->denumireCursa, denumireCursa);
			this->tip = new char[strlen(tip) + 1];
			strcpy(this->tip, tip);
			this->lungimeCursa = lungimeCursa;
		}

		//constructor de copiere

		Cursa(const Cursa& c) :idCursa(c.idCursa)
		{
			if (denumireCursa != NULL)
			{
				this->denumireCursa = new char[strlen(c.denumireCursa) + 1];
				strcpy(this->denumireCursa, c.denumireCursa);
			}
			if (tip != NULL)
			{
				this->tip = new char[strlen(c.tip) + 1];
				strcpy(this->tip, c.tip);
			}
			this->lungimeCursa = c.lungimeCursa;
		}

		//destructor

		~Cursa()
		{
			if (denumireCursa)
			{
				delete[] denumireCursa;
			}
			if (tip)
			{
				delete[] tip;
			}
		}

		//operator =

		Cursa operator=(const Cursa& c)
		{
			if (denumireCursa != NULL)
			{
				delete[] this->denumireCursa;
				this->denumireCursa = new char[strlen(c.denumireCursa) + 1];
				strcpy(this->denumireCursa, c.denumireCursa);

			}

			if (tip != NULL)
			{
				delete[] this->tip;
				this->tip = new char[strlen(c.tip) + 1];
				strcpy(this->tip, c.tip);
			}
			this->lungimeCursa = c.lungimeCursa;
			return *this;
		}

		char *getDenumireCursa()
		{
			return denumireCursa;
		}

		char *getTip()
		{
			return tip;
		}

		double getLungimeCursa()
		{
			return lungimeCursa;
		}

		int getIdCursa()
		{
			return idCursa;
		}

		void setDenumireCursa(char *denumireCursa)
		{
			if (denumireCursa != NULL)
			{
				delete[] this->denumireCursa;
				this->denumireCursa = new char[strlen(denumireCursa) + 1];
				strcpy(this->denumireCursa, denumireCursa);
			}
		}

		void setTip(char *tip)
		{
			if (tip != NULL)
			{
				delete[] this->tip;
				this->tip = new char[strlen(tip) + 1];
				strcpy(this->tip, tip);
			}
		}

		void setLungimeCursa(double lungimeCursa)
		{
			this->lungimeCursa = lungimeCursa;
		}

		friend ostream& operator<<(ostream&o, Cursa c);//functia friend pentru operatorul<<
		friend istream& operator>>(istream&i, Cursa&c);//functia friend pentru opratorul  <<


	};
	ostream& operator<<(ostream& o, Cursa c)//operatorul<<
	{
		o << "Denumirea cursei este : " << c.denumireCursa << endl;
		o << "Tipul cursei este : " << c.tip << endl;
		o << "LungimeaCursei este de : " << c.lungimeCursa;
		return o;
	}
	istream& operator>>(istream& i, Cursa& c)//operatorul>>
	{
		char aux[20];
		delete[] c.denumireCursa;
		cout << "Introduceti denumirea cursei: ";
		i >> aux;
		c.denumireCursa = new char[strlen(aux) + 1];
		strcpy(c.denumireCursa, aux);

		char auxiliara[20];
		delete[] c.tip;
		cout << "Introduceti tipul cursei: ";
		i >> auxiliara;
		c.tip = new char[strlen(auxiliara) + 1];
		strcpy(c.tip, auxiliara);

		cout << "Introduceti lungimea cursei este ";
		i >> c.lungimeCursa;
		return i;
	}

class Localitate
{
private:
	char* denumire;
	long long UTC;
	float latitudine;
	float longitudine;
	int viteza;

public:
	long long getUTC()
	{
		return UTC;
	}

	int getViteza()
	{
		return viteza;
	}

	void setUTC(long long UTC)
	{
		this->UTC = UTC;
	}

	void setViteza(int viteza)
	{
		this->viteza = viteza;
	}

	char* getDenumire()
	{
		return denumire;
	}

	float getLatitudine()
	{
		return latitudine;
	}

	float getLongitudine()
	{
		return longitudine;
	}

	void setDenumire(char* denumire)
	{
		if (denumire != NULL)
		{
			delete[] this->denumire;
			this->denumire = new char[strlen(denumire) + 1];
			strcpy(this->denumire, denumire);
		}
		else
		{
			denumire = new char[strlen("nedefinita") + 1];
			strcpy(denumire, "nedefinita");
		}

	}

	//constructor implicit

	Localitate()
	{
		this->denumire = new char[strlen("Birlad") + 1];
		strcpy(this->denumire, "Birlad");
		this->latitudine = 44.642;
		this->longitudine = 26.382;
		this->UTC = 1439467747492;
		this->viteza = 130;
	}

	//constructor explicit

	Localitate(char* denumire, long long UTC, float latitudine, float longitudine, int viteza)
	{
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
		this->UTC = UTC;
		this->latitudine = latitudine;
		this->longitudine = longitudine;
		this->viteza = viteza;
	}

	//constructor de copiere

	Localitate(const Localitate& l)
	{
		this->denumire = new char[strlen(l.denumire) + 1];
		strcpy(this->denumire, l.denumire);
		this->UTC = l.UTC;
		this->latitudine = l.latitudine;
		this->longitudine = l.longitudine;
		this->viteza = l.viteza;
	}

	//operator =

	Localitate operator=(const Localitate& l)
	{
		if (denumire)
		{
			delete[] this->denumire;
			this->denumire = new char[strlen(l.denumire) + 1];
			strcpy(this->denumire, l.denumire);
			this->UTC = l.UTC;
			this->latitudine = l.latitudine;
			this->longitudine = l.longitudine;
			this->viteza = l.viteza;
			return *this;
		}

	}
	//destructor

	~Localitate()
	{
		if (denumire)
			delete[] this->denumire;
	}

	void SalveazaBinar(char* numeFisier) //scrierea in fisier binar
	{
		ofstream f(numeFisier, ios::binary | ios::app); //deschidem un fisier binar
		f.write((char*)this, sizeof(Localitate));
		f.close();
	}
	void CitesteBinar(char* numeFisier)
	{
		ifstream g;
		g.open(numeFisier, ifstream::binary | ifstream::in);
		g.read((char*)this,sizeof(Localitate));
		g.close();
	}
	void SalveazaRaport(char* numeRaport)//scrierea raportului in fisier txt
	{
		ofstream f(numeRaport, ios::binary | ios::app);
		f << denumire << endl;
		f << latitudine << endl;
		f << longitudine << endl;
		f.close();
	}
	friend ostream &operator <<(ostream&out, Localitate temp);//functia friend pentru operatorul <<
	friend istream &operator >>(istream&in, Localitate&temp);//functia friend pentru operatorul >>
	friend ifstream &operator>>(ifstream&in, Localitate&temp);//functie friend pentru operatorul >> din fisier txt
	friend float DistantaParcursa(Localitate a, Localitate b);
	friend float VitMedie(Localitate a, Localitate b);
};
ostream &operator <<(ostream&out, Localitate temp) //operatorul <<
{
	out << "Numele localitatii este: " << temp.denumire << endl;
	out << "UTC: " << temp.UTC << endl;
	out << "Pozitionarea geografica: " << endl;
	out << "     Latitudine: " << temp.latitudine << endl;
	out << "     Longitudine: " << temp.longitudine << endl;
	out << "Viteza: " << temp.viteza << endl;
	return out;
}
istream &operator >>(istream&in, Localitate&temp) //operatorul >>
{
	char aux[20];
	delete[] temp.denumire;
	cout << "Introduceti numele localitatii: ";
	cin >> aux;
	temp.denumire = new char[strlen(aux) + 1];
	strcpy(temp.denumire, aux);
	cout << "Introduceti ora in formatul UTC: ";
	in >> temp.UTC;
	cout << "Introduceti coordonata latitudine: ";
	in >> temp.latitudine;
	cout << "Introduceti coordonata longitudine: ";
	in >> temp.longitudine;
	cout << "Introduceti viteza de deplasare: ";
	in >> temp.viteza;
	return in;
}
ifstream &operator>>(ifstream&in, Localitate&temp)
{

	char aux[20];
	delete[] temp.denumire;
	in.getline(aux, 19);
	temp.denumire = new char[strlen(aux) + 1];
	strcpy(temp.denumire, aux);
	in.ignore();
	in >> temp.UTC;
	in >> temp.latitudine;
	in >> temp.longitudine;
	in >> temp.viteza;
	return in;
}
float DistantaParcursa(Localitate a, Localitate b)
{
	float s;
	s = sqrt((a.latitudine - b.latitudine)*(a.latitudine - b.latitudine) + (a.longitudine - b.longitudine)*(a.longitudine - b.longitudine));
	return s;
}
float VitMedie(Localitate a, Localitate b)
{
	float s;
	s = (a.viteza + b.viteza) / 2;
	return s;
}


class Auto
{
private:
	char* model;
	char* tip;
	int vit_max;
	float capacitate_cilindrica;
	float consum_mediu_urban;
	int vit_medie_urban;
	float consum_mediu;
	int vit_medie;
public:
	Auto()//constructor implicit
	{
		this->model = new char[strlen("auto9") + 1];
		strcpy(this->model, "auto9");
		this->tip = new char[strlen("Benzina") + 1];
		strcpy(this->tip, "Benzina");
		this->vit_max = 290;
		this->capacitate_cilindrica = 1985;
		this->consum_mediu_urban = 7;
		this->vit_medie_urban = 50;
		this->consum_mediu = 6;
		this->vit_medie = 110;
	}

	Auto(char* model, char* tip, int vit_max, float capacitate_cilindrica, float consum_mediu_urban, int vit_medie_urban, float consum_mediu, int vit_medie)//constructor explicit
	{
		this->model = new char[strlen(model) + 1];
		strcpy(this->model, model);
		this->tip = new char[strlen(tip) + 1];
		strcpy(this->tip, tip);
		this->vit_max = vit_max;
		this->capacitate_cilindrica = capacitate_cilindrica;
		this->consum_mediu_urban = consum_mediu_urban;
		this->vit_medie_urban = vit_medie_urban;
		this->consum_mediu = consum_mediu;
		this->vit_medie = vit_medie;
	}

	Auto(const Auto& a) //constructor de copiere
	{
		this->model = new char[strlen(a.model) + 1];
		strcpy(this->model, a.model);
		this->tip = new char[strlen(a.tip) + 1];
		strcpy(this->tip, a.tip);
		this->vit_max = a.vit_max;
		this->capacitate_cilindrica = a.capacitate_cilindrica;
		this->consum_mediu_urban = a.consum_mediu_urban;
		this->vit_medie_urban = a.vit_medie_urban;
		this->consum_mediu = a.consum_mediu;
		this->vit_medie = a.vit_medie;
	}
	~Auto()
	{
		delete[] this->model;
		delete[] this->tip;
	}
	Auto operator=(const Auto a) //operator =
	{
		if (model != NULL)
			delete[] model;
		this->model = new char[strlen(a.model) + 1];
		strcpy(this->model, a.model);
		if (tip != NULL)
			delete[] tip;
		this->tip = new char[strlen(a.tip) + 1];
		strcpy(this->tip, a.tip);
		this->vit_max = a.vit_max;
		this->capacitate_cilindrica = a.capacitate_cilindrica;
		this->consum_mediu_urban = a.consum_mediu_urban;
		this->vit_medie_urban = a.vit_medie_urban;
		this->consum_mediu = a.consum_mediu;
		this->vit_medie = a.vit_medie;
		return *this;
	}
	char *getModel()
	{
		return model;
	}
	char *getTip()
	{
		return tip;
	}
	int get_vit_max()
	{
		return vit_max;
	}
	float get_capacitate_cilindrica()
	{
		return capacitate_cilindrica;
	}
	float get_consum_mediu_urban()
	{
		return consum_mediu_urban;
	}
	int get_vit_medie_urban()
	{
		return vit_medie_urban;
	}
	float get_consum_mediu()
	{
		return consum_mediu;
	}
	int get_vit_medie()
	{
		return vit_medie;
	}

	void setModel(char* tip)
	{
		if (tip != NULL)
		{
			delete[] this->model;
			this->model = new char[strlen(model) + 1];
			strcpy(this->model, model);
		}
		else
		{
			tip = new char[strlen(" ") + 1];
			strcpy(model, " ");
		}
	}
	void setTip(char* tip)
	{
		if (tip != NULL)
		{
			delete[] this->tip;
			this->tip = new char[strlen(tip) + 1];
			strcpy(this->tip, tip);
		}
		else
		{
			tip = new char[strlen(" ") + 1];
			strcpy(tip, " ");
		}
	}
	void set_vit_max(int vit_max)
	{
		this->vit_max = vit_max;
	}
	void setCapacitate_cilindrica(float capacitate_cilindrica)
	{
		this->capacitate_cilindrica = capacitate_cilindrica;
	}
	void set_consum_mediu_urban(float consum_mediu_urban)
	{
		this->consum_mediu_urban = consum_mediu_urban;
	}
	void set_vit_medie_urban(int vit_medie_urban)
	{
		this->vit_medie_urban = vit_medie_urban;
	}
	void set_consum_mediu(float consum_mediu)
	{
		this->consum_mediu = consum_mediu;
	}
	void set_vit_medie(int vit_medie)
	{
		this->vit_medie = vit_medie;
	}

	void SalveazaBinar(char* numeFisier)
	{
		ofstream f(numeFisier, ios::binary | ios::app); //deschidem un fisier binar
		f.write((char*)this, sizeof(Auto));
		f.close();
	}

	

	void CitesteBinar(char* numeFisier)
	{
		ifstream g(numeFisier,ios::binary | ios::in );
		g.read((char*)this,sizeof(Auto));
		g.close();
	}
	
	void SalveazaRaport(char* numeRaport)//scrierea raportului in fisier txt
	{
		ofstream f(numeRaport, ios::out | ios::app);
		f << model << endl;
		f << vit_max << endl;
		f << consum_mediu << endl;
		f.close();
	}
	void ScriereFisier()
	{
		ofstream f("auto.txt", ios::out | ios::app);
		f << model << endl;
		f << "engine: " << tip << endl;
		f << "max_speed: " << vit_max << endl;
		f << "engine_cc: " << capacitate_cilindrica << endl;
		f << "avg_consumption_urban: " << consum_mediu_urban << endl;
		f << "avg_speed_urban: " << vit_medie_urban << endl;
		f << "avg_consumption: " << consum_mediu << endl;
		f << "avg_speed: " << vit_medie << endl;
		f.close();
	}
	void RaportConsum()
	{
		cout << "consum mediu :" << consum_mediu << endl;
		cout << "consum mediu urban: " << consum_mediu_urban << endl;
	}
	void RaportTip()
	{
		cout << "tip motor: " << tip << endl;
	}
	void RaportCapCil()
	{
		cout << "capacitatea cilindrica: " << capacitate_cilindrica << endl;
	}
	friend ostream& operator<<(ostream& out, Auto t);
	friend istream& operator>>(istream& intrare, Auto&t);
	friend ifstream& operator>>(ifstream& intrare, Auto&t);
};
ostream& operator<<(ostream& out, Auto t)
{
	out << "model:" << t.model << endl;
	out << "tip: " << t.tip << endl;
	out << "viteza maxima: " << t.vit_max << endl;
	out << "capacitatea cilindrica: " << t.capacitate_cilindrica << endl;
	out << "consumul mediu urban: " << t.consum_mediu_urban << endl;
	out << "vireza medie urban: " << t.vit_medie_urban << endl;
	out << "consum mediu: " << t.consum_mediu << endl;
	out << "viteza medie: " << t.vit_medie << endl;
	return out;
}
istream& operator>>(istream& intrare, Auto&t)
{
	char aux[40];
	char aux1[20];
	cout << "introduceti modelul: ";
	intrare>>aux;
	delete[]t.model;
	t.model = new char[strlen(aux) + 1];
	strcpy(t.model, aux);
	intrare.ignore();
	cout << "introduceti tipul: ";
	delete[]t.tip;
	intrare>>aux1;
	t.tip = new char[strlen(aux1) + 1];
	strcpy(t.tip, aux1);
	intrare.ignore();
	cout << "introduceti viteza maxima: ";
	intrare >> t.vit_max;
	cout << "introduceti capacitatea motorului: ";
	intrare >> t.capacitate_cilindrica;
	cout << "introduceti consumul mediu urban: ";
	intrare >> t.consum_mediu_urban;
	cout << "introduceti viteza medie urban: ";
	intrare >> t.vit_medie_urban;
	cout << "introduceti consumul mediu: ";
	intrare >> t.consum_mediu;
	cout << "introduceti viteza medie: ";
	intrare >> t.vit_medie;
	return intrare;

}
ifstream& operator>>(ifstream& intrare, Auto&t)
{
	char aux[20];
	char aux1[20];
	char a[50];
	intrare.getline(aux, 19);
	delete[]t.model;
	t.model = new char[strlen(aux) + 1];
	strcpy(t.model, aux);
	intrare.ignore();
	intrare >> a;
	intrare.getline(aux1, 19);
	delete[]t.tip;
	t.tip = new char[strlen(aux1) + 1];
	strcpy(t.tip, aux1);
	intrare.ignore();
	intrare >> a;
	intrare >> t.vit_max;
	intrare >> a;
	intrare >> t.capacitate_cilindrica;
	intrare >> a;
	intrare >> t.consum_mediu_urban;
	intrare >> a;
	intrare >> t.vit_medie_urban;
	intrare >> a;
	intrare >> t.consum_mediu;
	intrare >> a;
	intrare >> t.vit_medie;
	return intrare;

}

class Geofence
{
protected:
	char* tip;
	char* restrictie;
public:
	char* get_tip()
	{
		return tip;
	}
	char* get_restrictie()
	{
		return restrictie;
	}
	void  set_tip(char* tip)
	{
		if (strlen(this->tip) > 2)
			delete[] this->tip;
		this->tip = new char[strlen(tip) + 1];
		strcpy(this->tip, tip);
	}
	void  set_restrictie(char* restrictie)
	{
		if (strlen(this->restrictie) > 2)
			delete[] this->restrictie;
		this->restrictie = new char[strlen(restrictie) + 1];
		strcpy(this->restrictie, restrictie);
	}
	Geofence()
	{
		this->tip = new char[strlen("patrat") + 1];
		strcpy(this->tip, "patrat");
		this->restrictie = new char[strlen("verde") + 1];
		strcpy(this->restrictie, "verde");

	}
	Geofence(char* tip, char* restricte)
	{
		this->tip = new char[strlen(tip) + 1];
		strcpy(this->tip, tip);
		this->restrictie = new char[strlen(restrictie) + 1];
		strcpy(this->restrictie, restrictie);
	}
	Geofence(const Geofence &g)
	{
		this->tip = new char[strlen(g.tip) + 1];
		strcpy(this->tip, g.tip);
		this->restrictie = new char[strlen(g.restrictie) + 1];
		strcpy(this->restrictie, g.restrictie);
	}
	Geofence operator=(const Geofence g)
	{
		delete[] this->tip;
		this->tip = new char[strlen(g.tip) + 1];
		strcpy(this->tip, g.tip);
		delete[] this->restrictie;
		this->restrictie = new char[strlen(g.restrictie) + 1];
		strcpy(this->restrictie, g.restrictie);
		return *this;
	}
	~Geofence()
	{
		delete[] tip;
		delete[] restrictie;
	}
	friend istream &operator>>(istream &in, Geofence &t);
	friend ostream &operator<< (ostream&out, Geofence t);
	friend ifstream &operator>>(ifstream &in, Geofence &t);
};
ostream &operator<< (ostream&out, Geofence t)
{
	out << "tip: " << t.tip << endl;
	out << "restrictions: " << t.restrictie << endl;
	return out;
}
istream &operator>>(istream &in, Geofence &t)
{
	char aux[20];
	char aux1[20];
	cout << "tip: ";
	in >> aux;
	delete[] t.tip;
	t.tip = new char[strlen(aux) + 1];
	strcpy(t.tip, aux);
	in.ignore();
	delete[] t.restrictie;
	cout << "restrictie: ";
	in.getline(aux1, 19);
	t.restrictie = new char[strlen(aux1) + 1];
	strcpy(t.restrictie, aux1);
	return in;
}
ifstream &operator>>(ifstream &in, Geofence&t)
{
	
		char a[50];
		char aux[20];
		char aux1[20];
		in >> a;
		in >> aux;
		delete[] t.tip;
		t.tip = new char[strlen(aux) + 1];
		strcpy(t.tip, aux);
		in.ignore();
		delete[] t.restrictie;
		in >> a;
		in.getline(aux1, 19);
		t.restrictie = new char[strlen(aux1) + 1];
		strcpy(t.restrictie, aux1);
		return in;
	
}

class Cerc :public Geofence
{
private:
	float latitudine;
	float longitudine;
	int raza;
public:
	float get_latitudine()
	{
		return latitudine;
	}
	float get_longitudine()
	{
		return longitudine;
	}
	int get_raza()
	{
		return raza;
	}
	void setLatitudine(float latitudine)
	{
		this->latitudine = latitudine;
	}
	void setLongitudine(float longitudine)
	{
		this->longitudine = longitudine;
	}
	void setRaza(int raza)
	{
		this->raza = raza;
	}
	Cerc() :Geofence()
	{
		latitudine = 12;
		longitudine = 21;
		raza = 11;
	}

	Cerc(char* tip, char *restrictie, float latitudine, float longitudine, int raza) : Geofence(tip, restrictie)
	{
		this->latitudine = latitudine;
		this->longitudine = longitudine;
		this->raza = raza;
	}
	Cerc(const Cerc &c) :Geofence(c)
	{
		this->latitudine = c.latitudine;
		this->longitudine = c.longitudine;
		this->raza = c.raza;
	}
	Cerc operator=(Cerc c)
	{
		Geofence::operator=(c);
		this->latitudine = c.latitudine;
		this->longitudine = c.longitudine;
		this->raza = c.raza;
		return *this;

	}
	~Cerc() {}
	void SalveazaBinar(char* numeFisier) //scrierea in fisier binar
	{
		ofstream f(numeFisier, ios::binary | ios::app); //deschidem un fisier binar
		f.write((char*)this, sizeof(Cerc));
		f.close();
	}

	void CitesteBinar(char* numeFisier)
	{
		ifstream f(numeFisier,ios::binary  | ios::app);
		f.read((char*)this,sizeof(Cerc));
		f.close();
	}
	friend istream &operator>>(istream&in, Cerc&c);
	friend ifstream &operator>>(ifstream&in, Cerc& c);
	friend ostream &operator<<(ostream&out, Cerc c);

};
istream &operator>> (istream&in, Cerc& c)
{
	char a[30];
	delete[] c.tip;
	cout << "tip: ";
	in>>a;
	c.tip=new char[strlen(a)+1];
	strcpy(c.tip,a);
	in.ignore();
	char aux[30];
	delete [] c.restrictie;
	cout << "restrictie: ";
	in>>aux;
	c.restrictie=new char[strlen(aux)+1];
	strcpy(c.restrictie,aux);
	in.ignore();
	cout << "latitudine: ";
	in >> c.latitudine;
	cout << "longitudine: ";
	in >> c.longitudine;
	cout << "raza: ";
	in >> c.raza;
	return in;
}
ifstream &operator>>(ifstream&in, Cerc& c)
{
char a[40];
 char aux[20];
 char aux1[20];
 in >> a;
 in >> aux;
 delete[] c.tip;
 c.tip = new char[strlen(aux) + 1];
 strcpy(c.tip, aux);
 in.ignore();
 delete[] c.restrictie;
 in >> a;
 in.getline(aux1, 19);
 c.restrictie = new char[strlen(aux1) + 1];
 strcpy(c.restrictie, aux1);
 in >> a;
 in >> c.latitudine;
 in >> a;
 in >> c.longitudine;
 in >> a;
 in >> c.raza;
 in >> a;
 return in;
}
ostream &operator<<(ostream&out, Cerc c)
{
	out << Geofence(c);
	out << "punct: " << c.latitudine << ";" << c.longitudine << endl;
	out << "raza: " << c.raza << " km" << endl;
	return out;
}

class Dreptunghi :public Geofence
{
private:
	float latitudine;
	float longitudine;
	float latitudine1;
	float longitudine1;

public:

	float get_latitudine()
	{
		return latitudine;
	}
	float get_longitudine()
	{
		return longitudine;
	}
	float get_latitudine1()
	{
		return latitudine1;
	}
	float get_longitudine1()
	{
		return longitudine1;
	}
	void setLatitudine(float latitudine)
	{
		this->latitudine = latitudine;
	}
	void setLongitudine(float longitudine)
	{
		this->longitudine = longitudine;
	}
	void setLatitudine1(float latitudine1)
	{
		this->latitudine1 = latitudine1;
	}
	void setLongitudine1(float longitudine1)
	{
		this->longitudine1 = longitudine1;
	}
	Dreptunghi() :Geofence()
	{
		latitudine = 23;
		longitudine = 32;
		latitudine1 = 45;
		longitudine1 = 54;
	}

	Dreptunghi(char* tip, char *restrictie, float latitudine, float longitudine, float latitudine1, float longitudine1) :Geofence(tip, restrictie)
	{
		this->latitudine = latitudine;
		this->longitudine = longitudine;
		this->latitudine1 = latitudine1;
		this->longitudine1 = longitudine1;

	}

	Dreptunghi(const Dreptunghi &d) :Geofence(d)
	{
		this->latitudine = d.latitudine;
		this->longitudine = d.longitudine;
		this->latitudine1 = d.latitudine1;
		this->longitudine1 = d.longitudine1;
	}
	Dreptunghi operator=(Dreptunghi d)
	{
		Geofence::operator=(d);
		this->latitudine = d.latitudine;
		this->longitudine = d.longitudine;
		this->latitudine1 = d.latitudine1;
		this->longitudine1 = d.longitudine1;
		return *this;

	}
	~Dreptunghi() {}
	void SalveazaBinar(char* numeFisier) //scrierea in fisier binar
	{
		ofstream f(numeFisier, ios::binary | ios::app); //deschidem un fisier binar
		f.write((char*)this, sizeof(Dreptunghi));
		f.close();
	}

	void CitesteBinar(char* numeFisier)
	{
		ifstream f(numeFisier,ios::binary  | ios::app);
		f.read((char*)this,sizeof(Dreptunghi));
		f.close();
	}

	friend istream&operator>>(istream&in, Dreptunghi &d);
	friend ifstream&operator>>(ifstream&in, Dreptunghi &d);
	friend ostream&operator<<(ostream&out, Dreptunghi d);


};
istream &operator>>(istream&in, Dreptunghi &d)
{
	char aux[20];
	char aux1[20];
	delete[] d.tip;
	cout<<"tip: ";
	in>>aux;
	d.tip=new char[strlen(aux)+1];
	strcpy(d.tip,aux);
	in.ignore();
	cout<<"restrictie: ";
	delete[]d.restrictie;
	in>>aux1;
	d.restrictie=new char[strlen(aux1)+1];
	strcpy(d.restrictie,aux1);
	in.ignore();
	cout << "latitudine: ";
	in >> d.latitudine;
	cout << "longitudine: ";
	in >> d.longitudine;
	cout << "latiduine1: ";
	in >> d.latitudine1;
	cout << "longitudine1: ";
	in >> d.longitudine1;
	return in;
}
ifstream &operator>>(ifstream&in, Dreptunghi& d)
{
char a[40];
 char aux[20];
 char aux1[20];
 in >> a;
 in >> aux;
 delete[] d.tip;
 d.tip = new char[strlen(aux) + 1];
 strcpy(d.tip, aux);
 in.ignore();
 delete[] d.restrictie;
 in >> a;
 in.getline(aux1, 19);
 d.restrictie = new char[strlen(aux1) + 1];
 strcpy(d.restrictie, aux1);
 in >> a;
 in >> d.latitudine;
 in >> a;
 in >> d.longitudine;
 in >> a;
 in >> d.latitudine1;
 in >> a;
 in >> d.longitudine1;
 return in;
}
ostream &operator<<(ostream&out, Dreptunghi d)
{
	out << Geofence(d);
	out << "colt_stanga_sus: " << d.latitudine << ";" << d.longitudine << endl;
	out << "colt_dreapta_jos: " << d.latitudine1 << ";" << d.longitudine1 << endl;
	return out;
}
void main(int argc, char *argv[])
	{
		
		cout << "Apelam constructorul fara parametri" << endl<<endl;
		Autovehicul z;
		cout << "marca masinii este: " << z.getMarca() << endl;
		z.setPret(9000);
		cout << "Pretul nou este: " << z.getPret() << endl;
		cout << z.getId()<<endl<<endl;

		cout << "Apelam constructorul explicit" << endl<<endl;
		Autovehicul a1("Dacia", "Sandero", 250, 7000,1);
		cout << "Viteza masinii: " << a1.getModel() << "este de " << a1.getViteza() << endl;
		cout << "Noua viteza a autovehiculuilui este de : ";
		a1.setViteza(300);
		cout << a1.getViteza()<<endl<<endl;

		cout << "Apelam constructorul de copiere: " <<endl<< endl;
		Autovehicul a2(a1);
		cout<<"Viteza masinii este de: "<<a2.getViteza()<<endl<<endl;//300

		cout<<"Apelam operator egal: "<<endl<<endl;
		Autovehicul a3;
		a3=z;
		cout<<"Pretul este: "<<a3.getPret()<<endl<<endl;

		cout << "Apeleam operatorii << si >>. " << endl << endl;
		Autovehicul a5;
		cin >> a5;
		cout << a5;
		

		
		cout<<"apelam constructor fara parametri pt Motor"<<endl<<endl;
		Motor m;
		cout << "Tipul motorului este: "<<endl;
		cout<<m.getTip()<<endl;
		m.setTip("Diesel");
		cout << "Tipul noului motor este: ";
		cout << m.getTip() << endl<<endl;

		cout << "Apelam constructorul cu parametri" << endl<<endl;
		float consum[5];
		consum[0] = 4.4;
		consum[1] = 6;
		consum[2] = 5.3;
		consum[3] = 3.2;
		consum[4] = 5.6;

		Motor m1("Benzina", 2.1, 160, 5, consum);
		cout << "Tipul motorului: " << m1.getTip() << endl;
		cout << "Capacitatea cilindrica: " << m1.getCapacitate_cilindrica() << endl;
		cout << "Puterea: " << m1.getPutere()<<endl;
		cout << "Consumurile sunt: " << endl;
		for (int i = 0;i < m1.getTeste() ;i++)
		cout <<m1.getConsum()[i] << endl<<endl;


		cout << "S-a apelat constructorul de copiere: " << endl<<endl;
		Motor m2=m;
		cout << "Puterea masinii este: "<< m2.getPutere()<<endl<<endl;

		cout<<"S-a apelat operatorul ="<<endl<<endl;
		Motor m3;
		m3=m2;
		cout << "Puterea masinii este: "<< m3.getPutere()<<endl<<endl;

		cout << "Apeleam operatorii << si >> " << endl << endl;
		Motor m4;
		cin >> m4;
		cout << m4;

		Motor m5;
		cout << "Apelam fuctia pentru a calcula consumul mediu." << endl<<endl;
		cout << "Consumul mediu al masinii m este: " << m5.consum_mediu() << endl<<endl ;
		

		
		cout<<"Apelam constructorul implicit."<<endl<<endl;
		Sofer s;
		cout << "Numele soferului: " << s.getNume() << endl;
		s.setNume("Valeriu");
		cout << "Numele modificat al soferului: " << s.getNume() << endl<<endl;

		cout << "S-a apelat constructorul cu parametri" << endl<<endl;
		float distantaParcursaPeSaptamana[7];
		distantaParcursaPeSaptamana[0]=12.4;
		distantaParcursaPeSaptamana[1]=22;
		distantaParcursaPeSaptamana[2]=10.2;
		distantaParcursaPeSaptamana[3]=10;
		distantaParcursaPeSaptamana[4]=12;
		distantaParcursaPeSaptamana[5]=10.7;
		distantaParcursaPeSaptamana[6]=10;
		Sofer s1("Violeta", 2130419802144, 20000,distantaParcursaPeSaptamana);
		cout << "Numele: " << s1.getNume() << endl;
		cout << "CNP-ul: " << s1.getCnp() << endl;
		cout << "Salariul: " << s1.getSalariu() << endl;
		cout << "Distantele parcurse in fiecare zi timp de o saptamana sunt: " << endl;
		for (int i = 0;i < 7 ;i++)
		cout<<s1.getDistantaParcursaPeSaptamana()[i] << endl<<endl;

		cout << "S-a apelat constructorul de copiere." << endl<<endl;
		Sofer s2=s;
		cout << "Numele: " << s2.getNume()<<endl<<endl;


		cout << "Apelam operatorii << si >>." << endl<<endl;
		Sofer s4;
		cin >> s4;
		cout << s4;
		

		
		Localitate l;
		cout << "Denumire auto: " << l.getDenumire() << endl;
		l.setDenumire("auto5");
		cout << "Denumire modificata: " << l.getDenumire() << endl << endl;

		cout << "S-a apelat constructorul cu parametri." << endl;
		Localitate b("auto1", 12345566, 23.3233,12.3455,130);
		cout << "Denumire: " << b.getDenumire() << endl;
		cout<<"UTC:"<<b.getUTC()<<endl;
		cout << "Latitudine: " << b.getLatitudine() << endl;
		cout << "Longitudine: " << b.getLongitudine() << endl << endl;
		cout<<"Viteza: "<<b.getViteza()<<endl<<endl;

		cout << "Apelam constructorul de copiere." << endl;
		Localitate l2=b;
		cout << "Numele: " << l2.getDenumire() << endl << endl;


		cout << "Apelam operatorii << si >>." << endl;
		cin >> l;
		cout << l;
		

		
		cout<<"Apelam constructorul implicit:"<<endl;
		Cursa w;
		cout << "Denumirea cursei: " << w.getDenumireCursa() << endl;
		w.setDenumireCursa("Bucuresti-Targu-Jiu");
		cout << "Denumire modificata: " << w.getDenumireCursa() << endl << endl;

		cout << "S-a apelat constructorul cu parametri." << endl;
		Cursa c1("Bucuresti-Magurele", "nationala", 130,3);
		cout << "Denumirea: " << c1.getDenumireCursa() << endl;
		cout << "Tipul: " << c1.getTip() << endl;
		cout << "Lungime cursa: " << c1.getLungimeCursa() << endl ;
		cout << "Id-ul cursei: "<<c1.getIdCursa()<<endl<<endl;

		cout << "Apelam constructorul de copiere." << endl;
		Cursa c2=w;
		cout << "Lungime cursa: " << c2.getLungimeCursa() << endl << endl;

		cout << "Apelam operatorii << si >>." << endl;
		Cursa c3;
		cin >> c3;
		cout << c3<<endl;
		cout<<"Denumire cursa: "<<c3.getDenumireCursa();
		
		
		
/*

	cout << "MENIU" << endl;
	cout << "   Pentru citirea din fisierul auto.txt, introduceti 1" << endl;
	cout << "   Pentru afisarea continutului din fisierul auto.txt, introduceti  2" << endl;
	cout << "   Pentru scrierea in fisier binar a continutului din fisierul auto.txt, introduceti  3" << endl;
	cout << "   Pentru citirea din fisierul telematics.txt, introduceti  4" << endl;
	cout << "   Pentru afisarea continutului din fisierul telematics.txt, introduceti  5" << endl;
	cout << "   Pentru scrierea in fisier binar a continutului din fisierul telematics.txt, introduceti 6" << endl;
	cout << "   Pentru citirea din fisierul geofence.txt, introduceti 7" << endl;
	cout << "   Pentru afisarea continutului din fisierul geofence.txt, introduceti  8" << endl;
	cout << "   Pentru scrierea in fisier binar a continutului din fisierul geofence.txt, introduceti  9" << endl;
	cout << "   Pentru a genera rapoarte, introduceti 10" << endl;
	cout << "   Pentru a adauga un nou autoturism in auto.txt, introduceti 20" << endl;
	cout << "   Pentru a sterge un fisier txt din cele primite in consola, introduceti 21" << endl;
	cout << "   Pentru citirea din fisier binar a continutului din fisierul auto.txt,introduceti 22" <<endl;
	cout << "   Pentru a inchide aplicatia, introduceti 0" << endl;

	int x;
	cin >> x;
	Auto autovehicul[3];
	Localitate* loc = new Localitate[65465];
	Cerc c;
	Dreptunghi d;
	Cerc a;
	while (x != 0)
	{
		if (x == 1)
		{
			ifstream g("auto.txt");
			for (int i = 0;i < 3;i++) //citirea obiectelor auto din fisier txt
			{
				g.ignore();
				g >> autovehicul[i];
			}
			cout << "done" << endl;
		}
		if (x == 2)
		{
			for (int i = 0;i < 3; i++)//afisare continut
			{
				cout << autovehicul[i];
				cout << endl;
			}
			cout << "done" << endl;
		}
		if (x == 3)
		{
			for (int i = 0;i < 3;i++) //scrierea fisierului auto.txt in fisier binar
				autovehicul[i].SalveazaBinar("auto.dat");
			cout << "Continutul a fost scris in fisierul auto.dat" << endl;;
		}
		if (x == 4)
		{
			ifstream f("telematics.txt");
			for (int i = 0;i < 65465;i++)
			{
				f.ignore();
				f >> loc[i];
			}
			cout << "done" << endl;
		}
		if (x == 5)
		{
			//afisarea tututor inregistrarilor
			for (int i = 0;i < 65465; i++)
			{
				cout << loc[i];
				cout << endl;
			}
			cout << "done" << endl;
		}
		if (x == 6)
		{
			for (int i = 0;i < 65465;i++) //scrierea fisierului auto.txt in fisier binar
				loc[i].SalveazaBinar("telematics.dat");
			cout << "Continutul a fost scris in fisierul telematics.dat" << endl;
		}
		if (x == 7)
		{
			ifstream g("geofence.txt");
			g >> c;
			g.ignore();
			g >> d;
			g.ignore();
			g >> a;
			cout << "done" << endl;
		}
		if (x == 8)
		{
			cout << c << endl;
			cout << d << endl;
			cout << a << endl;
			cout << "done" << endl;
		}
		if (x == 9)
		{
			c.SalveazaBinar("geofence.dat");
			d.SalveazaBinar("geofence.dat");
			a.SalveazaBinar("geofence.dat");
			cout << "Continutul a fost scris in fisierul geofence.dat" << endl;
		}
		if (x == 10)
		{
			cout << "      Afisarea vitezei maxime si medii pentru fiecare auto in functie de tipul acestuia, introduceti 11" << endl;
			cout << "      Afisarea consumului mediu pentru fiecare auto in functie de tipul acestuia, introduceti 12" << endl;
			cout << "      Afisarea tipului motorului pentru fiecare auto in functie de tipul acestuia, introduceti 13" << endl;
			cout << "      Afisarea capacitatii cilindrice a motorului pentru fiecare auto in functie de tipul acestuia, introduceti 14" << endl;
			cout << "      Afisarea distantelor parcurse de auto in functie de tipul acestuia, introduceti 15" << endl;
			cout << "      Afisarea denumirii,latitudinii si longitudinii in functie de tipul auto, introduceti 16" << endl;
			cout << "      Afisarea tipurilor restrictiilor de pe harta, introduceti 17" << endl;
			cout << "      Afisarea tipurilor de restrictie cu culoarea aferenta, introduceti 18" << endl;
			cout << "      Sa se afiseze daca auto sunt GreenDriving in functie de tipul acestora,introduceti 19" << endl;
		}
		if (x == 11)
		{
			char y[20];
			cout << "Introduceti tipul auto: ";
			cin >> y;
			while (strcmp("back", y) != 0)
			{
				if (strcmp("auto1", y) == 0)
					autovehicul[0].SalveazaRaport("raportAuto.txt");
				if (strcmp("auto2", y) == 0)
					autovehicul[1].SalveazaRaport("raportAuto.txt");
				if (strcmp("auto3", y) == 0)
					autovehicul[2].SalveazaRaport("raportAuto.txt");
				cout << "Introduceti tipul auto: ";
				cin >> y;
			}
			cout << "Rezultatul este afisat in fisierul raportAuto.txt" << endl;
		}
		if (x == 12)
		{
			char y[20];
			cout << "Introduceti tipul auto: ";
			cin >> y;
			while (strcmp("back", y) != 0)
			{
				if (strcmp("auto1", y) == 0)
					autovehicul[0].RaportConsum();
				if (strcmp("auto2", y) == 0)
					autovehicul[1].RaportConsum();
				if (strcmp("auto3", y) == 0)
					autovehicul[2].RaportConsum();
				cout << endl;
				cout << "Introduceti tipul auto: ";
				cin >> y;
			}
		}
		if (x == 13)
		{
			char y[20];
			cout << "Introduceti tipul auto: ";
			cin >> y;
			while (strcmp("back", y) != 0)
			{
				if (strcmp("auto1", y) == 0)
					autovehicul[0].RaportTip();
				if (strcmp("auto2", y) == 0)
					autovehicul[1].RaportTip();
				if (strcmp("auto3", y) == 0)
					autovehicul[2].RaportTip();
				cout << endl;
				cout << "Introduceti tipul auto: ";
				cin >> y;
			}
		}
		if (x == 14)
		{
			char y[20];
			cout << "Introduceti tipul auto: ";
			cin >> y;
			while (strcmp("back", y) != 0)
			{
				if (strcmp("auto1", y) == 0)
					autovehicul[0].RaportCapCil();
				if (strcmp("auto2", y) == 0)
					autovehicul[1].RaportCapCil();
				if (strcmp("auto3", y) == 0)
					autovehicul[2].RaportCapCil();
				cout << endl;
				cout << "Introduceti tipul auto: ";
				cin >> y;
			}
		}
		if (x == 15)
		{
			char y[20];
			cout << "Introduceti tipul auto: ";
			cin >> y;
			while (strcmp("back", y) != 0)
			{
				if (strcmp("auto1", y) == 0)
				{
					float distParcursa = 0;
					float vitMedie = 0;
					for (int i = 0;i < 65464;i++)
					{
						if (strcmp("auto1", loc[i].getDenumire()) == 0
							&& strcmp("auto1", loc[i + 1].getDenumire()) == 0)
						{
							float a;
							a = DistantaParcursa(loc[i], loc[i + 1]);
							distParcursa = distParcursa + a;
							float b;
							b = VitMedie(loc[i], loc[i + 1]);
							vitMedie = (vitMedie + b) / 2;
						}
					}
					cout << "distanta parcursa este: " << distParcursa << endl;
					cout << "cu viteza medie de: " << vitMedie << endl;
				}
				if (strcmp("auto2", y) == 0)
				{
					float distParcursa = 0;
					float vitMedie = 0;
					for (int i = 0;i < 65464;i++)
					{
						if (strcmp("auto2", loc[i].getDenumire()) == 0
							&& strcmp("auto2", loc[i + 1].getDenumire()) == 0)
						{
							float a;
							a = DistantaParcursa(loc[i], loc[i + 1]);
							distParcursa = distParcursa + a;
							float b;
							b = VitMedie(loc[i], loc[i + 1]);
							vitMedie = (vitMedie + b) / 2;
						}
					}
					cout << "distanta parcursa este: " << distParcursa << endl;
					cout << "cu viteza medie de: " << vitMedie << endl;
				}
				if (strcmp("auto3", y) == 0)
				{
					float distParcursa = 0;
					float vitMedie = 0;
					for (int i = 0;i < 65464;i++)
					{
						if (strcmp("auto3", loc[i].getDenumire()) == 0
							&& strcmp("auto3", loc[i + 1].getDenumire()) == 0)
						{
							float a;
							a = DistantaParcursa(loc[i], loc[i + 1]);
							distParcursa = distParcursa + a;
							float b;
							b = VitMedie(loc[i], loc[i + 1]);
							vitMedie = (vitMedie + b) / 2;
						}
					}
					cout << "distanta parcursa este: " << distParcursa << endl;
					cout << "cu viteza medie de: " << vitMedie << endl;
				}
				cout << endl;
				cout << "Introduceti tipul auto: ";
				cin >> y;
			}
		}
		if (x == 16)
		{
			char y[20];
			cout << "Introduceti tipul auto: ";
			cin >> y;
			while (strcmp("back", y) != 0)
			{
				if (strcmp("auto1", y) == 0)
				{
					for (int i = 0;i < 26447;i++)
						loc[i].SalveazaRaport("raportLoc.txt");
				}
				if (strcmp("auto2", y) == 0)
				{
					for (int i = 26447;i < 51667;i++)
						loc[i].SalveazaRaport("raportLoc.txt");
				}
				if (strcmp("auto3", y) == 0)
				{
					for (int i = 51667;i < 65465;i++)
						loc[i].SalveazaRaport("raportLoc.txt");
				}
				cout << "Introduceti tipul auto: ";
				cin >> y;
			}
			cout << "Rezultatul este afisat in fisierul raportLoc.txt" << endl;
		}
		if (x == 17)
		{
			cout << c.get_tip() << endl << d.get_tip() << endl << "done" << endl;
		}
		if (x == 18)
		{
			cout << c.get_tip() << " are culoarea restrictiei " << c.get_restrictie() << endl;
			cout << d.get_tip() << " are culoarea restrictiei " << d.get_restrictie() << endl;
			cout << a.get_tip() << " are culoarea restrictiei " << a.get_restrictie() << endl;
		}
		if (x == 19)
		{
			char y[20];
			cout << "Introduceti tipul auto: ";
			cin >> y;
			while (strcmp("back", y) != 0)
			{
				if (strcmp("auto1", y) == 0)
				{
					if (autovehicul[0].get_consum_mediu_urban() <= 10 && autovehicul[0].get_consum_mediu() <= 7)
						cout << "Auto1 este GreenDriving." << endl;
					else
						cout << "Auto1 nu este GreenDriving." << endl;
				}
				if (strcmp("auto2", y) == 0)
				{
					if (autovehicul[1].get_consum_mediu_urban() <= 10 && autovehicul[1].get_consum_mediu() <= 7)
						cout << "Auto2 este GreenDriving." << endl;
					else
						cout << "Auto2 nu este GreenDriving." << endl;
				}
				if (strcmp("auto3", y) == 0)
				{
					if (autovehicul[2].get_consum_mediu_urban() <= 10 && autovehicul[2].get_consum_mediu() <= 7)
						cout << "Auto3 este GreenDriving." << endl;
					else
						cout << "Auto3 nu este GreenDriving." << endl;
				}
				cout << "Introduceti tipul auto: ";
				cin >> y;
			}

		}
		if (x == 20)
		{
			Auto a;
			cin >> a;
			a.ScriereFisier();
			cout << "s-a adaugat!" << endl;
		}
		if (x == 21)
		{
			char y[20];
			cout << "Introduceti fisierul ce va fi sters: ";
			cin >> y;
			while (strcmp("back", y) != 0)
			{
				if (strcmp("auto.txt", y) == 0)
				{
					remove("auto.txt");
					cout << "fisierul a fost sters!" << endl;
				}
				if (strcmp("telematics.txt", y) == 0)
				{
					remove("telematics.txt");
					cout << "fisierul a fost sters!" << endl;
				}
				if (strcmp("geofence.txt", y) == 0)
				{
					remove("geofence.txt");
					cout << "fisierul a fost sters!" << endl;
				}
				cout << "Introduceti fisierul ce va fi sters: ";
				cin >> y;
			}
		}
		cin >> x;
	}
	
	*/
	

	}