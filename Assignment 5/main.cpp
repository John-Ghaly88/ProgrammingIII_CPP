#include <iostream>
#include <cstdlib>

using namespace std;

class mystring{
private:
    size_t occupied;
    size_t capacity;
    char *sequence;

public:
    mystring()
    {
        this->occupied = 0;
        this->capacity = 15;
        this->sequence = new char [capacity];
    }

    mystring(const char str[]){
        int n = 0, j = 0;
        while(str[j] != (char) 0){
            n++, j++;
        }
        n = n-3;
        occupied = 0;
        capacity = n;
        sequence = new char [capacity];
        for (int i = 0; i < n; i++){
            sequence[i] = str[i];
            occupied++;
        }
    }

    mystring(const string str){
        int n = str.size();
        occupied = 0;
        capacity = n;
        sequence = new char [capacity];
        for (int i = 0; i < n; i++){
            sequence[i] = str[i];
            occupied++;
        }
    }

    mystring(const mystring& source){
        this->occupied = source.occupied;
        this->capacity = source.capacity;
        this->sequence = new char[source.capacity];
        for(int i = 0 ;i <= capacity; i++)
            this->sequence[i] = source.sequence[i];
    }

    virtual ~mystring(){
        delete [] sequence;
    }

    mystring& operator+= (const mystring& addend){
        string s;
        for(int i = 0 ; i < this->capacity; i++)
            s[i] = this->sequence[i];
        for(int j = this->capacity, z = 0; j < addend.capacity; j++, z++)
            s[j] = addend.sequence[z];

        this->occupied = this->occupied + addend.occupied;
        this->capacity = this->capacity + addend.capacity;
        this->sequence = new char[this->capacity];

        for (int i = 0; i < addend.capacity; i++)
            this->sequence[i] = s[i];

        return * this;
    }

    mystring& operator+=(const char addend[]){
        int n = 0, j = 0;
        while(addend[j] != (char) 0){
            n++, j++;
        }
        n = n-3;

        string s;
        for(int i = 0 ; i < this->capacity; i++)
            s[i] = this->sequence[i];
        for(int j = this->capacity, z = 0; j < n; j++, z++)
            s[j] = addend[z];

        this->occupied = this->occupied + n;
        this->capacity = this->capacity + n;
        this->sequence = new char[this->capacity];

        for (int i = 0; i < n; i++)
            this->sequence[i] = s[i];

        return * this;
    }

    mystring& operator+=(const char addend){
        string s;
        for(int i = 0; i<this->capacity; i++)
            s.push_back(sequence[i]);
        s.push_back(addend);

        this->occupied = this->occupied + 1;
        this->capacity = this->capacity + 1;
        this->sequence = new char[this->capacity];

        for (int i = 0; i < this->capacity; i++)
            this->sequence[i] = s[i];

        return * this;
    }

    mystring& operator=(const mystring& source){
        * this = source; //it just calls the copy constructor
        return (* this);
    }

    char& operator[](size_t position){
        return sequence[position];
    }

    size_t length() const {return occupied;}

    const char* c_str() const {return sequence;}

    void swap(mystring& x){
        size_t occupied_temp = this->occupied;
        this->occupied = x.occupied;
        x.occupied = occupied_temp;


        size_t capacity_temp = this->capacity;
        this->capacity = x.capacity;
        x.capacity = capacity_temp;

        char * sequence_temp = this->sequence;
        this->sequence = x.sequence;
        x.sequence = sequence_temp;
    }

    bool is_empty(){ return (occupied == 0); }

    friend bool operator==(mystring& s1, mystring& s2);
    friend bool operator!=(mystring& s1, mystring& s2);
    friend bool operator>=(mystring& s1, mystring& s2);
    friend bool operator<=(mystring& s1, mystring& s2);
    friend bool operator> (mystring& s1, mystring& s2);
    friend bool operator< (mystring& s1, mystring& s2);

    friend ostream& operator <<(ostream& outs, const mystring& source);
    friend istream& operator>>(istream& ins, mystring& target);
};

mystring operator+(mystring& s1, mystring& s2){
    s1.operator+=(s2);
    return s1;
}

mystring operator+(mystring& s1, char* s2){
    s1.operator+=(s2);
    return s1;
}

mystring operator+(char* s1, mystring& s2){
    s2.operator+=(s1);
    return s2;
}

bool operator==(mystring& s1, mystring& s2){
    return (s1.occupied == s2.occupied);
}

bool operator!=(mystring& s1, mystring& s2){
    return (s1.occupied != s2.occupied);
}

bool operator>=(mystring& s1, mystring& s2){
    return (s1.occupied >= s2.occupied);
}

bool operator<=(mystring& s1, mystring& s2){
    return (s1.occupied <= s2.occupied);
}

bool operator> (mystring& s1, mystring& s2){
    return (s1.occupied > s2.occupied);
}

bool operator< (mystring& s1, mystring& s2){
    return (s1.occupied < s2.occupied);
}

ostream& operator <<(ostream& outs, const mystring& source){
    for(int i = 0; i < source.capacity; i++)
            outs << source.sequence[i];
        return outs;
}

istream& operator>>(istream& ins, mystring& target){
    string s;
    ins >> s;

    int n = s.size();
    target.capacity = n;
    target.occupied = 0;
    target.sequence = new char [target.capacity];
    for (int i = 0; i < n; i++){
        target.sequence[i] = s[i];
        target.occupied++;
    }
    return ins;
}

int main()
{
    string x = "Jo";
    char y [] = {'h','n','n'};

    mystring * s = new mystring();
    mystring s1 (x);
    mystring s2 (y);

    cout<<s1[0];

    //s1+=s2;
    //mystring s3 = y + s1;

    //if (s1<=s2)
    //  cout<< "yess";
    //else
    //  cout<<"no";


    //cin >> s1;
    //cout << s1;

    return 0;
}
