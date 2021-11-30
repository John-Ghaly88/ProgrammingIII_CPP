#include <bits/stdc++.h>
using namespace std;

class Article{
public:
    int numberOfArticel, orderDuration;
    string description;
    double costPrice;

    Article(string n, string d, string c, string o){
        numberOfArticel = stoi(n);
        description = d;
        costPrice = stod(c);
        orderDuration = stoi(o);
    }
};

class Stock{
public:
    static int totalStock;
    int articleNumber, actualStock, maximumStock, consumption;

    Stock(string n, string as, string ms, string c){
        articleNumber = stoi(n);
        actualStock = stoi(as);
        maximumStock = stoi(ms);
        consumption = stoi(c);

        totalStock += stoi(as);
    }
};

int Stock::totalStock = 0;

int rop(Article a, Stock s){
    int lead_time_demand, safety_stock;

    lead_time_demand = a.orderDuration * s.consumption;
    safety_stock = 2 * s.consumption;

    return lead_time_demand + safety_stock;
}

string orderProposal(Article a, Stock s){
    if (s.actualStock <= rop(a,s))
        return "Yes";
    else
        return "No";
}

int main()
{
    fstream in;
    in.open("input.csv", ios::in);

    string line, word;
    string l0[7], l1[7], l2[7], l3[7], l4[7];

    //Row 1 (read)
    getline(in, line);
    stringstream t0(line);
    for(int i=0; i<7; i++)
        getline(t0, l0[i], ',');

    Article a0(l0[0], l0[1], l0[4], l0[6]);
    Stock s0(l0[0], l0[2], l0[3], l0[5]);

    //Row 2 (read)
    getline(in, line);
    stringstream t1(line);
    for(int i=0; i<7; i++)
        getline(t1, l1[i], ',');

    Article a1(l1[0], l1[1], l1[4], l1[6]);
    Stock s1(l1[0], l1[2], l1[3], l1[5]);

    //Row 3 (read)
    getline(in, line);
    stringstream t2(line);
    for(int i=0; i<7; i++)
        getline(t2, l2[i], ',');

    Article a2(l2[0], l2[1], l2[4], l2[6]);
    Stock s2(l2[0], l2[2], l2[3], l2[5]);

    //Row 4 (read)
    getline(in, line);
    stringstream t3(line);
    for(int i=0; i<7; i++)
        getline(t3, l3[i], ',');

    Article a3(l3[0], l3[1], l3[4], l3[6]);
    Stock s3(l3[0], l3[2], l3[3], l3[5]);

    //Row 5 (read)
    getline(in, line);
    stringstream t4(line);
    for(int i=0; i<7; i++)
        getline(t4, l4[i], ',');

    Article a4(l4[0], l4[1], l4[4], l4[6]);
    Stock s4(l4[0], l4[2], l4[3], l4[5]);


    cout << "The total stock value is: " << Stock::totalStock <<endl;


    fstream out;
    out.open("output.csv", ios::out | ios::app);

    //Row 1 (write)
    out << to_string(a0.numberOfArticel) << "," << a0.description << "," << to_string(s0.actualStock) << ","
    << to_string(s0.maximumStock) << "," << to_string(a0.costPrice) << "," << to_string(s0.consumption) << ","
    << to_string(a0.orderDuration) << "," << to_string(rop(a0,s0)) << "," << orderProposal(a0,s0) << "\n";

    //Row 2 (write)
    out << to_string(a1.numberOfArticel) << "," << a1.description << "," << to_string(s1.actualStock) << ","
    << to_string(s1.maximumStock) << "," << to_string(a1.costPrice) << "," << to_string(s1.consumption) << ","
    << to_string(a1.orderDuration) << "," << to_string(rop(a1,s1)) << "," << orderProposal(a1,s1) << "\n";

    //Row 3 (write)
    out << to_string(a2.numberOfArticel) << "," << a2.description << "," << to_string(s2.actualStock) << ","
    << to_string(s2.maximumStock) << "," << to_string(a2.costPrice) << "," << to_string(s2.consumption) << ","
    << to_string(a2.orderDuration) << "," << to_string(rop(a2,s2)) << "," << orderProposal(a2,s2) << "\n";

    //Row 4 (write)
    out << to_string(a3.numberOfArticel) << "," << a3.description << "," << to_string(s3.actualStock) << ","
    << to_string(s3.maximumStock) << "," << to_string(a3.costPrice) << "," << to_string(s3.consumption) << ","
    << to_string(a3.orderDuration) << "," << to_string(rop(a3,s3)) << "," << orderProposal(a3,s3) << "\n";

    //Row 5 (write)
    out << to_string(a4.numberOfArticel) << "," << a4.description << "," << to_string(s4.actualStock) << ","
    << to_string(s4.maximumStock) << "," << to_string(a4.costPrice) << "," << to_string(s4.consumption) << ","
    << to_string(a4.orderDuration) << "," << to_string(rop(a4,s4)) << "," << orderProposal(a4,s4) << "\n";


    return 0;
}
