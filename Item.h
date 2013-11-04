
#include <string>
using namespace std;

typedef std::vector<double> Vector;
class Item
{
public:
	Item();
	Item(double c, char t);
	~Item();
	double coif;
	char type;
	double calcul(double x);
};