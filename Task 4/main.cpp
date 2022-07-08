#include <iostream>

using namespace std;

class Medium{
private:
    string abbrev;
    string author;
    string title;
    int year;

public:
    Medium(){
    }

    Medium(string ab, string au, string t, int y){
        abbrev = ab;
        author = au;
        title = t;
        year = y;
    }

    virtual ~Medium(){
    }

    string getAbbrev(){
        return abbrev;
    }

    void setAbbrev(string a){
        abbrev = a;
    }

    string getAuthor(){
        return author;
    }

    void setAuthor(string a){
        author = a;
    }

    string getTitle(){
        return title;
    }

    void setTitle(string t){
        title = t;
    }

    string getYear(){
        return  to_string(year);
    }

    void setYear(int y){
        year = y;
    }

    virtual string toString(){
        return "[" + abbrev + "] " + author + ": " + title + ".";
    }
};

class Book: public Medium{
private:
    string publisher;

public:
    Book (string ab, string au, string t, int y, string p): Medium(ab,au,t,y){
        publisher = p;
    }

    string getPublisher(){
        return publisher;
    }

    void setPublisher(string p){
        publisher = p;
    }

    string toString()override{
        return Medium::toString() + " " + publisher + ", " + Medium::getYear() + ".";
    }
};

class Article: public Medium{
private:
    string magazineName;
    int magazineNo;
    int pageNo;

public:
    Article (string ab, string au, string t, int y, string mna, int mno, int pn): Medium(ab,au,t,y){
        magazineName = mna;
        magazineNo = mno;
        pageNo = pn;
    }

    string getMagazineName(){
        return magazineName;
    }

    void setMagazineName(string m){
        magazineName = m;
    }

    string getMagazineNo(){
        return to_string(magazineNo);
    }

    void setMagazineNo(int m){
        magazineNo = m;
    }

    string getPageNo(){
        return to_string(pageNo);
    }

    void setPageNo(int p){
        pageNo = p;
    }

    string toString()override{
        return Medium::toString()+" "+magazineName+", "+to_string(magazineNo)+", "+Medium::getYear()+", "+to_string(pageNo)+".";
    }
};

class Bibliography{
private:
    Medium * a[0];
public:
    Bibliography(int size){
        Medium * a[size];
    }

    static int index;
    void insert (Medium * m){
        a[++index] = m;
    }

    Medium * operator[](string ab){
        Medium * r = NULL;
        for(int i = 0; i <= index; i++)
            if (a[i] -> getAbbrev() == ab)
                r = a[i];
        return r;
    }

    friend ostream& operator <<(ostream &os, const Bibliography &b);
};
int Bibliography::index = -1;

ostream& operator <<(ostream &os, const Bibliography &b){
         for(int i = 0; i <= b.index; i++)
            os << b.a[i] -> toString() << endl;
        return os;
}

int main()
{
    Bibliography myBibliography(10);

    Book* b1 = new Book("Ra01","Dietmar Ratz","Grundkurs Programmieren in Java",2001,"Hanser-Verlag");
    Book* b2 = new Book("Kr03","Guido Krueger","Handbuch der Java-Programmierung",2003,"Addison-Wesley");
    Article* a1 = new Article("Pa72","D. L. Parnas","On the Criteria To Be Used in Decomposing Systems into Modules",1972,"Communications of the ACM",15,1053);

    myBibliography.insert(b1);
    myBibliography.insert(b2);
    myBibliography.insert(a1);
    cout << "Bibliography:" << endl << myBibliography;
    cout << endl << (*myBibliography["Pa72"]).toString() << endl;

    return 0;
}
