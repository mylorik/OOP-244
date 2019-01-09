///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/07/28      
///////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include <iomanip>
#include "Product.h"
#include "ErrorState.h"
#include <cstring>
using namespace std;
using namespace AMA;

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

	Product::~Product()
	{
		delete[] name_;
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
		return (tax_status_) ? price() * (taxRate + 1) : price();
	}

	void Product::message(const char* error_mess)
	{
		error_state_.message(error_mess);
	}

	bool Product::isClear() const
	{
		return error_state_.isClear();
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

	std::fstream& Product::store(std::fstream& file, const bool new_line = true) const
	{
		file << type_ << ',' << sku_ << ',' << unit_ << ',' << name_ << ',' << qty_have_ << "," << tax_status_ << "," <<
			price_ << "," << qty_need_;
		if (new_line)
			file << endl;
		return file;
	}

	std::fstream& Product::load(std::fstream& file)
	{
		Product temp;

		temp.name_ = new char[max_name_length + 1];

		if (file.is_open())
		{
			file >> temp.type_ >> temp.sku_ >> temp.unit_ >> temp.name_ >> temp.qty_have_ >> temp.tax_status_ >> temp.price_ >>
				temp.qty_need_;
			*this = temp;
		}

		delete[] temp.name_;
		temp.name_ = nullptr;

		return file;
	}

	std::ostream& Product::write(std::ostream& os, const bool if_true) const
	{
		if (if_true)
		{
			os << setw(max_sku_length) << left << sku_ << '|'
				<< setw(20) << left << name_ << '|'
				<< setw(7) << right << fixed << setprecision(2) << cost() << '|'
				<< setw(4) << right << qty_have_ << '|'
				<< setw(10) << left << unit_ << '|'
				<< setw(4) << right << qty_need_ << '|';
		}
		else
		{
			os << "Sku: " << sku_ << "|" << endl
				<< "Name: " << name_ << "|" << endl
				<< "Price: " << price_ << "|" << endl;
			if (tax_status_)
			{
				os << "Price after tax: " << cost() << "|" << endl;
			}
			else
			{
				os << "N/A"
					<< "|" << endl;
			}
			os << "Quantity On hand: " << qty_have_ << "|" << endl
				<< "Quantity needeed: " << qty_need_ << "|" << endl;
		}
		return os;
	}

	std::istream& Product::read(std::istream& is)
	{
		char sku[max_sku_length + 1];
		auto address = new char[max_name_length + 1];
		char unit[max_unit_length + 1];
		int qty_have;
		int qty_need;
		double price;
		char tax;
		bool tax_status;
		ErrorState error;

		cout << " Sku: ";
		is >> sku;
		cout << " Name (no spaces): ";
		is >> address;
		cout << " Unit: ";
		is >> unit;
		cout << " Taxed? (y/n): ";
		is >> tax;

		if (tax == 'Y' || tax == 'y')
		{
			tax_status = true;
		}
		else if (tax == 'N' || tax == 'n')
		{
			tax_status = false;
		}
		else
		{
			is.setstate(std::ios::failbit);
			error.message("Only(Y)es or (N)o are acceptable");
		}

		if (!is.fail())
		{
			cout << " Price: ";
			is >> price;
			if (is.fail())
				error.message("Invalid Price Entry");
		}

		if (!is.fail())
		{
			cout << " Quantity on hand: ";
			is >> qty_have;
			if (is.fail())
				error.message("Invalid Quantity Entry");
		}

		if (!is.fail())
		{
			cout << " Quantity needed: ";
			is >> qty_need;
			if (is.fail())
				error.message("Invalid Quantity Needed Entry");
		}

		if (!is.fail())
		{
			const auto temp = Product(sku, address, unit, qty_have, tax_status, price, qty_need);
			*this = temp;
		}

		delete[] address;
		address = nullptr;
		return is;
	}

	bool Product::operator==(const char* address) const
	{
		return strcmp(address, this->sku_) == 0;
	}

	double Product::total_cost() const
	{
		const auto taxes = price_ * taxRate;
		const auto final_price = price_ + taxes;

		return static_cast<double>(qty_have_ * final_price);
	}

	void Product::quantity(const int units)
	{
		qty_have_ = units;
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
		return (strcmp(sku_, address) > 0) ? true : false;
	}

	bool Product::operator>(const Product& other) const
	{
		return (strcmp(name_, other.name_) > 0) ? true : false;
	}

	int Product::operator+=(const int to_add)
	{
		if (to_add > 0)
		{
			qty_have_ += to_add;
			return qty_have_;
		}
		return qty_have_;
	}

	std::ostream& operator<<(std::ostream& os, const Product& other)
	{
		return other.write(os, true);
	}

	std::istream& operator>>(std::istream& is, Product& other)
	{
		other.read(is);
		return is;
	}

	double operator+=(double& total, const Product& other)
	{
		return total + other.total_cost();
	}
}
