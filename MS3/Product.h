///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/07/28      
///////////////////////////////////////////////////////////

#ifndef PRODUCT_H
#define PRODUCT_H

#include "ErrorState.h"

namespace AMA
{
	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double taxRate = 0.13;

	class Product : public ErrorState
	{
		char type_;
		char* name_;
		char sku_[max_sku_length + 1];
		char unit_[max_unit_length + 1];
		bool tax_status_;
		double price_;
		int qty_have_;
		int qty_need_;
		ErrorState error_state_;

	protected:
		void name(const char*);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double price() const;
		double cost() const;
		void message(const char*) override;
		bool isClear() const override;
	public:
		Product(char type = 'N');
		Product(const char* sku, const char* address, const char* unit, int qty_have = 0, bool tax_status = true,
		        double price = 0.0, int qty_need = 0);
		Product(const Product&);
		~Product();

		std::fstream& store(std::fstream&, bool) const;
		std::fstream& load(std::fstream&);
		std::ostream& write(std::ostream&, bool) const;
		std::istream& read(std::istream&);

		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;

		bool operator>(const char*) const;
		bool operator>(const Product&) const;
		Product& operator=(const Product&);
		int operator+=(int);
	};

	std::ostream& operator<<(std::ostream&, const Product&);
	std::istream& operator>>(std::istream&, Product&);
	double operator+=(double&, const Product&);
}
#endif
