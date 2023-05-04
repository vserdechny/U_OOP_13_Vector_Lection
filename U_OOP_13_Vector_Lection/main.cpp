#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

template <typename T>
void print_vector_with_info(const vector<T>& v, const string& msg);

int main()
{
	cout << "Example of using std::vector<T> collection" << endl;
	cout << "Vitaly Serdechny, May 2023" << endl << endl;

	//******************************************
	// Initializing
	//******************************************
	//1. Default ctor => an empty vector (size = 0, capacity = 0, no values)
	vector<int> i_testvec;
	//2. Ctor with size
	vector<double> d_testvec(10);
	//3. Ctor with size and default values
	//vector<string> s_testvec(5, "--noname--");
	//4. Ctor with another vector
	//vector<string> s_copy_testvec(s_testvec);

	//******************************************
	// Detecting size and capacity + accessing to values
	//******************************************
	print_vector_with_info(i_testvec, "i_testvec info:");
	print_vector_with_info(d_testvec, "\n\nd_testvec info:");

	cout << endl << endl;

	d_testvec[0] = 10.5;
	d_testvec.at(1) = 2.5;

	//******************************************
	// Adding new values (memory management principles)
	//******************************************
	cout << endl << endl;
	cout << "Pushing back 50 values to i_testvec vector:" << endl;
	cout << "Capcity growth dynamic: ";
	for (size_t i = 0; i < 50; i++)
	{
		size_t capacity = i_testvec.capacity();
		i_testvec.push_back(static_cast<int>(i));
		if (capacity != i_testvec.capacity())
			cout << capacity << " ";
	}

	cout << endl << endl;
	print_vector_with_info(i_testvec, "i_testvec info:");

	//******************************************
	// Iterators (+auto, range-based for statement, insert method of vector)
	//******************************************
	cout << endl << endl;
	cout << "Printing values of d_testvec vector with const iterator:\n";
	for (const auto& i : d_testvec)
		cout << i << " ";
	cout << endl << endl;

	cout << "Printing values of d_testvec vector with const reverse iterator:\n";
	for (auto it = d_testvec.crbegin(); it < d_testvec.crend(); it++)
		cout << *it << " ";
	cout << endl << endl;

	d_testvec.insert(d_testvec.begin(), 3.5);
	d_testvec.insert(d_testvec.begin() + d_testvec.size() / 2, 1.5);
	
	cout << "Inserting value {3.5} at the beginning of vector d_testvec and {1.5} at the middle:\n";
	print_vector_with_info(d_testvec, "d_testvec info:");

	//******************************************
	// Removing values
	//******************************************
	i_testvec.pop_back();
	cout << endl << endl;
	print_vector_with_info(i_testvec, "i_testvec info after removing the last value:");

	i_testvec.erase(i_testvec.begin());
	cout << endl << endl;
	print_vector_with_info(i_testvec, "i_testvec info after removing the first value:");

	i_testvec.erase(i_testvec.begin(), i_testvec.begin() + 3);
	cout << endl << endl;
	print_vector_with_info(i_testvec, "i_testvec info after removing first 3 value:");

	i_testvec.clear();
	cout << endl << endl;
	print_vector_with_info(i_testvec, "i_testvec after removing all values:");

	//******************************************
	// Size control methods
	//******************************************
	i_testvec.shrink_to_fit();

	print_vector_with_info(i_testvec, "i_testvec info after shrink_to_fit method:");

	i_testvec.reserve(20);

	print_vector_with_info(i_testvec, "i_testvec info after reserving 20 values:");

	d_testvec.resize(3);

	print_vector_with_info(d_testvec, "d_testvec info after resizing to 3 values:");
}

template <typename T>
void print_vector_with_info(const vector<T>& v, const string& msg)
{
	cout << msg << endl;
	cout << "Size: " << v.size() << endl;
	cout << "Capacity: " << v.capacity() << endl;
	cout << "Empty status: " << v.empty() << endl << endl;
	cout << "Values:" << endl;
	for (size_t i = 0; i < v.size(); i++)
		cout << v[i] << " ";
}

