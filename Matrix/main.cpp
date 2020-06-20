#include <algorithm>
#include <iostream>
using namespace std;
class matrix
{
private:
    int* mat;
    int size;
public:
    matrix(int s = 0) : size(s) {
        mat = 0;
        setsize(s);
    }
    ~matrix()
    {
        if (mat)
            delete mat;
    }
    matrix& mul(matrix& ob1, matrix& ob2);
    void getmat()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cin >> mat[i * size + j];
            }
        }
    }
    void setsize(int n1)
    {
        size = n1;
        if (mat)
            delete mat;
        mat = new int[size * size];
    }
    int getsize() { return size; }
    void masout() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << mat[i * size + j] << "  ";
            }
            cout << endl;
        }
    }


}obj1, obj2, obj3, result;

matrix& matrix::mul(matrix& ob1, matrix& ob2)
{
    this->setsize(min(ob1.getsize(), ob2.getsize()));

    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            this->mat[k * size + i] = 0;
            for (int j = 0; j < size; j++) {
                this->mat[k * size + i] += ob1.mat[k * size + j] * ob2.mat[j * size + i];
            }
        }
    }
    return *this;
}


int main()
{
    int n;
    cout << "Type size for first matrix: "; cin >> n;
    obj1.setsize(n);
    obj1.getmat();
    cout << "Type size for second matrix: "; cin >> n;
    obj2.setsize(n);
    obj2.getmat();
    cout << "first matrix: \n";
    obj1.masout();
    cout << "second matrix: \n";
    obj2.masout();
    obj3.setsize(min(obj1.getsize(), obj2.getsize()));
    cout << "result" << endl;
	obj3.mul(obj1, obj2).masout();
}