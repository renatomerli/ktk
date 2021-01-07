//data.cpp -> objetos para dados como venda, item, cliente, etc


#ifndef DATAH
#define DATAH

#include<gtkmm.h>

class Operador
{
	Operador();
	~Operador();

	int codigo;
//	string nome;
//	int set (int _codigo, ustring senha);

};

class Cliente
{
	Cliente ();
    Cliente (int codigo);
	~Cliente ();
	
	int codigo;
	bool set (int _codigo);
};


class VendaItem
{

	VendaItem(int _cod, int _qtd);
	~VendaItem();

	int cod;
	int qtd;
	float preco;
	float total;
	int set (int _cod, int _qtd);
};


class Venda
{
	Venda();
	~Venda();
	
	std::vector<VendaItem> itens;
	int num_itens;
	float valor_total;

	bool addItem (VendaItem _item);
	bool removeItem (VendaItem _item);
};

class Ticket
{
    Ticket();
    Ticket();
    ~Ticket();
    
    
long num;
Venda _venda;
};



#endif
