#include <iostream>
#include <sstream>
using namespace std;

template <typename T>
class Vector {
private:
    size_t dimension;
    T * values;
public:
    Vector(){
        this->dimension = 0;
        this->values = new T[this->dimension];
    }

    Vector(T * v, size_t d) {
        this->dimension = d;
        this->values = new T[this->dimension];
        for(int i = 0 ; i < this->dimension; i++)
            this->values[i] = v[i];
    }

    Vector(T * v){
        int n = 0, j = 0;
        while(v[j] != NULL)
            n++, j++;
        this->dimension = n;
        this->values = new T[this->dimension];
        for(int i = 0 ; i < this->dimension; i++)
            this->values[i] = v[i];
    }

    Vector(size_t d){
        this->dimension = d;
        this->values = new T[dimension];
        for(int i = 0 ; i < this->dimension; i++)
            this->values[i] = NULL;
    }

    Vector(const Vector & v){
        this->dimension = v.dimension;
        this->values = new T[v.dimension];
        for(int i = 0 ; i < this->dimension; i++)
            this->values[i] = v.values[i];
    }

    ~Vector(){
        delete[] values;
    }

    size_t size(){
        return this->dimension;
    }

    void resize(size_t x){
        size_t old = this->dimension;
        this->dimension = x;
        T temp [old];
        for(int i = 0 ; i < old; i++)
            temp[i] = this->values[i];
        delete[] this->values;
        this->values = new T[this->dimension];
        for(int i = 0 ; i < old; i++)
            this->values[i] = temp[i];
        for(int i = old ; i < this->dimension; i++)
            this->values[i] = NULL;
    }

    void swap (T * v){
        size_t dimension_temp = this->dimension;
        this->dimension = v.dimension;
        v.dimension = dimension_temp;

        T * values_temp = this->values;
        this->values = v.values;
        v.values = values_temp;
    }

    string toString(){
        string s = "";
        s += "(";
        for(int i = 0 ; i < this->dimension -1; i++){
            stringstream ss;
            ss << *(values + i);
            s += ss.str();
            s += ",";
        }
        stringstream ss;
        ss <<  *(values + (this->dimension -1));
        s += ss.str();
        s += ")";
        return s;
    }

    T& operator[](size_t pos){
        if ((pos >= this->dimension) || (pos < 0))
            throw out_of_range("Invalid index (out of range)");
        return this->values[pos];
    }

    Vector& operator=(const Vector& v){
        this->dimension = v.dimension;
        this->values = new T[v.dimension];
        for(int i = 0 ; i < this->dimension; i++)
            this->values[i] = v.values[i];
    }

    void insert(Vector & v, int pos){
        if ((pos >= this->dimension) || (pos < 0))
            throw out_of_range("Invalid index (out of range)");
        int old = this->dimension;
        this->resize(old+v.dimension);
        for(int i = old-1; i >= pos; i--)
            this->values[i+v.dimension] = this->values[i];
        for(int i = 0, j = pos; i < v.dimension; i++, j++)
            this->values[j] = v[i];
    }

    void insert(T x, int pos){
        if ((pos >= this->dimension) || (pos < 0))
            throw out_of_range("Invalid index (out of range)");
        this->dimension++;
        for(int i = this->dimension-2; i >= pos; i--)
            this->values[i+1] = this->values[i];
        this->values[pos] = x;
    }

    void remove(size_t pos){
        if ((pos >= this->dimension) || (pos < 0))
            throw out_of_range("Invalid index (out of range)");
        this->dimension--;
        for(int i = pos; i < this->dimension; i++)
            this->values[i] = this->values[i+1];
        this->values[this->dimension] = NULL;
    }
};

template <typename T>
ostream& operator <<(ostream& outs, Vector<T>& v){
        outs << v.toString();
        return outs;
}

int main() {
    //int test [5] = {1,2,3,4,5};
    //Vector<int> v1;
    //Vector<int> v(test, 5);
    //Vector<int> v(5);
    //cout<<v;
    //cout<<v.size();
    //cout<<v[2];
    //cout<<v[8];
    //v1 = v;
    //cout<<v1;

    //int x [5] = {1,2,3,4,5};
    //Vector<int> v(x);
    //int y [5] = {6,7,8};
    //Vector<int> v1(y);
    //v.remove(0);
    //cout<<v;
    //v.insert(y,1);
    //v.insert(10,3);
    //cout<<v;

    return 0;
}
