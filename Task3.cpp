#include <iostream>
#include <list>
#include <numeric>
#include <iterator>
#include <vector>
#include <iomanip>
#include<optional>
#include <cstddef>

using namespace std;

/*************1************/
void show(const list<double>& box) {
	copy(box.begin(), box.end(), ostream_iterator<double>(cout, " "));
	puts("");
}
void sred(list<double>& box) {
	auto avg = accumulate(box.begin(), box.end(), 0.0) / box.size();
	box.push_back(avg);
}

/**************2************/

class Matrix
{
public:
	Matrix(istream& is);

	void printMatrix()
	{
		for (const auto& i : matrix)
		{
			for (const auto& j : i)
			{
				cout << setw(3) << j << setw(2) << "";
			}
			cout << endl;
		}
	}
	void printAnswer()
	{
		if (determinant) std::cout << "Определитель матрицы = " << determinant.value();
		else cout << "Определитель не найден";
		cout << endl;
	}

protected:
	Matrix(const Matrix& prevMatrix, const size_t& expansion_string_element_index) : determinant(NULL), size(prevMatrix.size - 1)
	{
		matrix.reserve(size);
		for (size_t i = 0; i < size; i++)
		{
			matrix.push_back(vector<int>());
			matrix[i].reserve(size);
			for (size_t j = 0; j < prevMatrix.size; j++)
			{
				if (expansion_string_element_index != j) matrix[i].push_back(prevMatrix.matrix[i + 1][j]);
			}
		}
		calculate();
	}
	void calculate()
	{
		switch (size)
		{
		case 1:
			determinant = matrix[0][0];
			break;
		case 2:
			determinant = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
			break;
		default:
			minors.reserve(size);
			determinant = 0;
			for (size_t i = 0; i < size; i++)
			{
				minors.push_back(Matrix(*this, i));
				determinant.emplace() = determinant.value() + matrix[0][i] * minors[i].determinant.value() * (i % 2 == 0 ? 1 : (-1));
			}
			break;
		}
	}

private:
	vector<vector<int>> matrix;
	size_t size;
	optional<int> determinant;
	vector<Matrix> minors;
};


/*****************3********/

const int SIZE = 10;

class Itr
{
private:

	int m_data[SIZE];
public:
	class Iterator {
	public:
		using iterator_category = forward_iterator_tag;
		using difference_type = ptrdiff_t;
		using value_type = int;
		using pointer = int*;
		using reference = int&;

		Iterator(int* ptr)
			: m_ptr(ptr) {}


		int& operator*() const { return *m_ptr; }
		int* operator->() { return m_ptr; }
		Iterator& operator++() {
			m_ptr++;
			return *this;
		}
		Iterator& operator++(int) {
			Iterator temp = *this;
			++(*this);
			return temp;
		}
		friend bool operator!=(const Iterator& a, const Iterator& b) { return (a.m_ptr != b.m_ptr); }
		friend bool operator==(const Iterator& a, const Iterator& b) { return (a.m_ptr == b.m_ptr); }


	private:
		int* m_ptr;
	};

	Iterator begin() { return Iterator(&m_data[0]); }
	Iterator end() { return Iterator(&m_data[SIZE]); }
};

int main() {
	//1
	{
	list<double> box{ 2.5, 3.7, 4.9, 1.8, 6.2 };
	show(box);
	sred(box);
	show(box);
	system("pause > nul");
	}
	//2
		{
			Matrix mtrx(cin);
			cout << endl;
			mtrx.printMatrix();
			mtrx.printAnswer();
			return 0;
		}

	//3
		{
			int arr[5] = { 0,1,2,3,4 };
			for (auto it : arr)
			{
				cout << it << " ";
			}

		}
}









