///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/07/28      
///////////////////////////////////////////////////////////

#ifndef AMA_PERISHABLE_H__
#define AMA_PERISHABLE_H__

#include "Product.h"
#include "Date.h"

namespace AMA
{
	class Perishable : public Product
	{
		Date perishable_date_;
	public:
		Perishable();

		std::fstream& store(std::fstream& file, bool newLine = true) const override;
		std::fstream& load(std::fstream& file) override;
		std::ostream& write(std::ostream& os, bool linear) const override;
		std::istream& read(std::istream& is) override;
		const Date& expiry() const;
	};

	iProduct* CreatePerishable();
}

#endif