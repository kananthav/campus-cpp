#include <iostream>
//#include <conio.h>
#include <string.h>

using namespace std;

struct salesperson //ini ganti pake ctrl + r
{
    bool checker = false; // ini ganti
    string personID;
    double salesbyQuarter[4];
    double totalSales;
};

double calTotalSales(salesperson person)
{
    double total = 0.0;
    for(int i = 0;i<4;i++)
    {
        total = total + person.salesbyQuarter[i];
    }
    return total;
}
salesperson addSalesPerson(salesperson sales)
{
    //nama sales ganti
    cout << "Sales person" << endl;
    cout << "Person id : ";
    cin >> sales.personID;
    for(int i = 0; i < 4; i++)
    {
        int j = i + 1;
        cout << "Quarter number " << j << " : ";
        cin >> sales.salesbyQuarter[i];
    }
    double total = calTotalSales(sales);
    sales.totalSales = total;
    sales.checker = true;
    return sales;
    //lolok
}

void detMaxSales (salesperson (&sales)[10])
{
    string highestID;
    double highestSale = 0.0;
    for(int i = 0;i<10;i++)
    {
        if(sales[i].checker == false){
            break;
        }
        else
        {
            if(highestSale < sales[i].totalSales){
                highestSale = sales[i].totalSales;
                highestID = sales[i].personID;
            }
        }
    }
    cout << "Max Sale by SalesPerson : ID = " << highestID << " ,Amount = RM" << highestSale << endl;

    //cout << sales[0].personID << endl;
}
void detMaxQuart (salesperson (&sales)[10])
{
    int highestQ;
    double quart[] = {0.0,0.0,0.0,0.0};
    double highestAmount = 0;

    double amount = 0.0;
    for(int i = 0;i < 10;i++)
    {
        if(sales[i].checker == false)
        {
            break;
        }
        else
        {
            quart[0] = quart[0] + sales[i].salesbyQuarter[0];
            quart[1] = quart[1] + sales[i].salesbyQuarter[1];
            quart[2] = quart[2] + sales[i].salesbyQuarter[2];
            quart[3] = quart[3] + sales[i].salesbyQuarter[3];
        }
    }
    for(int j = 0; j < 4; j++)
    {
        if(highestAmount < quart[j])
        {
            highestAmount = quart[j];
            highestQ = j + 1;
        }

    }
    cout << "Max Sale by Quarter: Quarter = " << highestQ << ", Amount = RM" << highestAmount <<endl;
    //lolok


}

void displayReport (salesperson sales[10])
{
    double quart[] = {0.0,0.0,0.0,0.0};
    cout << "ID" << "\t\t";
    cout << "QT1" << "\t\t";
    cout << "QT2" << "\t\t";
    cout << "QT3" << "\t\t";
    cout << "QT4" << "\t\t";
    cout << "Total" << endl;
    cout << "**************************************************************************************" <<endl; //**** diganti pake ------ lolok
    for(int i = 0; i < 10; i++)
    {
        if(sales[i].checker == false)
        {
            break;
            cout << "no data entered yet" << endl;
        }
        else
        {
            quart[0] = quart[0] + sales[i].salesbyQuarter[0];
            quart[1] = quart[1] + sales[i].salesbyQuarter[1];
            quart[2] = quart[2] + sales[i].salesbyQuarter[2];
            quart[3] = quart[3] + sales[i].salesbyQuarter[3];
            cout << sales[i].personID << "\t\t";
            cout << sales[i].salesbyQuarter[0] << "\t\t";
            cout << sales[i].salesbyQuarter[1] << "\t\t";
            cout << sales[i].salesbyQuarter[2] << "\t\t";
            cout << sales[i].salesbyQuarter[3] << "\t\t";
            cout << calTotalSales(sales[i]) << endl;

        }
    }
    cout << "Total" << "\t\t";
    cout << quart[0] << "\t\t";
    cout << quart[1] << "\t\t";
    cout << quart[2] << "\t\t";
    cout << quart[3] << "\n" << endl;
    //bangsat


}

int main()
{
    int counter = 0;
    salesperson person[10];
    int chooser;
    cout << "1. Enter sales information" << endl;
    cout << "2. Print Report(as per the output defined)" << endl;
    cout << "3. Exit" << endl;
    cout << "Your choice : ";
    cin >> chooser;
    do //anjing
    {
        switch(chooser)
        {
        case 1:
            if(counter < 10)
            {
            person[counter] = addSalesPerson(person[counter]);
            counter++;
            }else
            {
            cout << "Sales Information is full!" << endl;
            }
            cout << "Your choice : ";
            cin >> chooser;
            break;
        case 2:
            displayReport(person);
            detMaxSales(person);
            detMaxQuart(person);
            cout << "Your choice : ";
            cin >> chooser;
            break;
        case 3:
            break;
        default:
            cout << "invalid input" << endl;
            cout << "Your choice : ";
            cin >> chooser;
            break;
        }
    }while(chooser != 3);


    return 0;
}

