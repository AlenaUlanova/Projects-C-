#include <iostream>
#include <list>
#include <numeric>
#include <iterator>
#include <vector>
#include <iomanip>
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
    int s;
    vector<vector<int>> M;

    int Ac(vector<vector<int>> Matr, int raw, int col, int sz)
    {
        --sz;
        int offset_i, offset_j = 0;
        vector<vector<int>> tempM;
        tempM.reserve(sz);
        for (int i = 0; i < sz; i++)
        {
            if (i == raw) offset_i = 1;
            tempM.push_back(vector<int>());
            tempM[i].reserve(sz);
            offset_j = 0;
            for (int j = 0; j < sz; j++)
            {
                if (j == col) offset_j = 1;
                tempM[i].push_back(Matr[i + offset_i][j + offset_j]);
            }
        }

        int result = Determinant(tempM, sz);
        return col % 2 == 0 ? result : -result;
    }

    int Determinant(vector<vector<int>> Matr, int sz)
    {
        switch (sz)
        {
        case 1:
            return Matr[0][0];
            break;
        case 2:
            return Matr[0][0] * Matr[1][1] - Matr[1][0] * Matr[0][1];
            break;
        default:
            int sum = 0;
            for (int i = 0; i < sz; i++)
            {
                sum += Matr[0][i] * Ac(Matr, 0, i, sz);
            }
            return sum;
            break;
        }
    }
public:
    Matrix() {};
    void Initialize()
    {
        cout << "Введите размер матрицы: "; cin >> s;
        M.reserve(s);
        for (int i = 0; i < s; i++)
        {
            M.push_back(std::vector<int>());
            M[i].reserve(s);
            for (int j = 0; j < s; j++)
            {
                int element;
                cout << "Введите элемент: " << '[' << i + 1 << "] [" << j + 1 << ']';
                cin >> element;
                M[i].push_back(element);
            }
        }
    }

    void Print()
    {
        cout << "Матрица:\n";
        for (const auto& i : M)
        {
            for (const auto& j : i)
            {
                cout << j;
            }
            cout << endl;
        }
    }

    int Result()
    {
        return Determinant(M, s);
    }
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
		Matrix m;
		m.Initialize();
		m.Print();
		cout << "Детерминант: " << m.Result();
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









