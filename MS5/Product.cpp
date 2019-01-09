///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/07/28      
///////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Product.h"
#include <cstring>
using namespace std;

namespace AMA
{
	Product::Product(const char type)
	{
		type_ = type;
		name_ = nullptr;
		sku_[0] = '\0';
		unit_[0] = '\0';
		tax_status_ = false;
		price_ = 0.0;
		qty_have_ = 0;
		qty_need_ = 0;
	}

	Product::Product(const char* sku, const char* address, const char* unit,
	                 const int qty_have, const bool tax_status, const double price, const int qty_need)
	{
		name(address);
		strncpy(sku_, sku, max_sku_length);
		sku_[max_sku_length] = '\0';

		strncpy(unit_, unit, max_unit_length);
		unit_[max_unit_length] = '\0';

		tax_status_ = tax_status;
		price_ = price;
		qty_have_ = qty_have;
		qty_need_ = qty_need;
	}

	Product::Product(const Product& other)
	{
		const int name_size = strlen(other.name_);

		type_ = other.type_;

		strncpy(sku_, other.sku_, max_sku_length);
		sku_[max_sku_length] = '\0';
		strncpy(unit_, other.unit_, max_unit_length);
		unit_[max_unit_length] = '\0';

		tax_status_ = other.tax_status_;
		price_ = other.price_;
		qty_have_ = other.qty_have_;
		qty_need_ = other.qty_need_;

		if (other.name_ != nullptr)
		{
			name_ = nullptr;
			name_ = new char[name_size];

			for (auto i = 0; i < name_size; ++i)
			{
				name_[i] = other.name_[i];
			}
			name_[name_size] = '\0';
		}
		else
		{
			name_ = nullptr;
		}
	}

	Product::~Product()
	{
		delete[] name_;
	}

	std::fstream& Product::store(std::fstream& file, bool newLine) const
	{
		file << type_ << ',' << sku_ << ',' << name_ << ',' << unit_
		<< ',' << tax_status_ << ',' << price_ << ',' << qty_have_ << ',' << qty_need_;

		if (newLine)
			file << endl;

		return file;
	}

	std::fstream& Product::load(std::fstream& file)
	{
		char sku[max_sku_length];
		char unit[max_unit_length];
		char name[max_name_length];
		double price;
		int qty_have;
		int qty_need;
		char tax;
		auto tax_status = false;

		if (file.is_open())
		{
			file.getline(sku, max_sku_length, ',');
			sku[strlen(sku)] = '\0';

			file.getline(name, max_name_length, ',');
			name[strlen(name)] = '\0';

			file.getline(unit, max_unit_length, ',');
			unit[strlen(unit)] = '\0';

			file >> tax;
			tax_status = tax == '1';
			file.ignore();
			file >> price;
			file.ignore();
			file >> qty_have;
			file.ignore();
			file >> qty_need;
			file.ignore();

			*this = Product(sku, name, unit, qty_have, tax_status, price, qty_need);
		}

		return file;
	}

	std::ostream& Product::write(std::ostream& os, bool linear) const
	{
		if (!isClear())
		{
			os << error_state_.message();
			return os;
		}

		if (linear)
		{
			os << setw(max_sku_length) << left << sku() << '|' << setw(20) << left << name() << '|' << setw(7)
				<< right << fixed << setprecision(2) << cost() << '|' << setw(4) << right << quantity() << '|'
				<< setw(10) << left << unit() << '|' << setw(4) << right << qtyNeeded() << '|';
			return os;
		}

		os << " Sku: " << sku() << endl << " Name (no spaces): " << name() << endl << " Price: " << price() << endl;

		if (tax_status_)
			os << " Price after tax: " << cost() << endl;
		else
			os << " Price after tax: N/A" << endl;

		os << " Quantity on Hand: " << quantity() << ' ' << unit() << endl << " Quantity needed: " << qtyNeeded();
		
		return os;
	}

	std::istream& Product::read(std::istream& is)
	{
		char tax_status;
		const auto address = new char[max_name_length + 1];
		//const auto sku = new char[max_sku_length + 1];
		int qty_have;
		int qty_need;
		double price;

		if (!is.fail())
		{
			cout << " Sku: ";
			is >> sku_;

			cout << " Name (no spaces): ";
			is >> address;
			name(address);

			cout << " Unit: ";
			is >> unit_;

			cout << " Taxed? (y/n): ";
			is >> tax_status;

				if (tax_status)
				{
					if ( tax_status == 'y' || tax_status == 'Y')
						tax_status_ = true;
					else if(tax_status == 'n' || tax_status == 'N' )
						tax_status_ = false;
					else
					{
						is.setstate(std::ios::failbit);
						clear();
						message("Only (Y)es or (N)o are acceptable");
						return is;
					}
				}

			cout << " Price: ";
			is >> price;

			if (is.fail())
			{
				clear();
				is.setstate(ios::failbit);
				message("Invalid Price Entry");
				return is;
			}
			price_ = price;

			cout << " Quantity on hand: ";
			is >> qty_have;

			if (is.fail())
			{
				clear();
				message("Invalid Quantity Entry");
				is.setstate(ios::failbit);
				return is;
			}
			quantity(qty_have);

			cout << " Quantity needed: ";
			is >> qty_need;

			if (is.fail())
			{
				clear();
				message("Invalid Quantity Needed Entry");
				is.setstate(ios::failbit);
				return is;
			}
			qty_need_ = qty_need;
		}
		clear();
		is.ignore();
		return is;
	}


	bool Product::operator==(const char* address) const
	{
		return strcmp(address, this->sku_) == 0;
	}

	double Product::total_cost() const
	{
		return qty_have_ * cost();
	}

	void Product::quantity(int quantity)
	{
		qty_have_ = quantity;
	}

	bool Product::isEmpty() const
	{
		return name_ == nullptr;
	}

	int Product::qtyNeeded() const
	{
		return qty_need_;
	}

	int Product::quantity() const
	{
		return qty_have_;
	}

	bool Product::operator>(const char* address) const
	{
		return strcmp(sku_, address) > 0 ? true : false;
	}

	bool Product::operator>(const iProduct& other) const
	{
		return strcmp(name_, other.name()) > 0 ? true : false;
	}

	Product& Product::operator=(const Product& other)
	{
		if (this != &other)
		{
			type_ = other.type_;
			strncpy(sku_, other.sku(), max_sku_length);
			strncpy(unit_, other.unit(), max_unit_length);

			tax_status_ = other.tax_status_;
			price_ = other.price_;
			qty_have_ = other.qty_have_;
			qty_need_ = other.qty_need_;

			delete[] name_;
			if (other.name_ != nullptr)
			{
				const int length = strlen(other.name_);

				name_ = new char[length];
				for (auto i = 0; i < length; ++i)
				{
					name_[i] = other.name_[i];
				}
				name_[length] = '\0';
			}
			else
			{
				name_ = nullptr;
			}
		}

		return *this;
	}

	int Product::operator+=(const int to_add)
	{
		if (to_add > 0)
		{
			qty_have_ += to_add;
		}
		return qty_have_;
	}

	void Product::name(const char* name_ptr)
	{
		if (name_ptr != nullptr)
		{
			const int length = strlen(name_ptr);

			name_ = new char[length];
			for (auto i = 0; i < length; ++i)
			{
				name_[i] = name_ptr[i];
			}
			name_[length] = '\0';
		}
		else
		{
			delete[] name_;
			name_ = nullptr;
		}
	}

	const char* Product::name() const
	{
		return (name_[0] == '\0') ? nullptr : name_;
	}

	const char* Product::sku() const
	{
		return sku_;
	}

	const char* Product::unit() const
	{
		return unit_;
	}

	bool Product::taxed() const
	{
		return tax_status_;
	}

	double Product::price() const
	{
		return price_;
	}

	double Product::cost() const
	{
		return tax_status_ ? price() * (taxRate + 1) : price();
	}

	void Product::message(const char* error_mess)
	{
		if (error_mess != nullptr)
			error_state_.message(error_mess);
	}

	void Product::clear()
	{
		error_state_.clear();
	}

	bool Product::isClear() const
	{
		return error_state_.isClear();
	}

	std::ostream& operator<<(std::ostream& os, const iProduct& other)
	{
		return other.write(os, true);
	}

	std::istream& operator>>(std::istream& is, iProduct& other)
	{
		return other.read(is);
	}

	double operator+=(double& total, const iProduct& other)
	{
		return total + other.total_cost();
	}
}
