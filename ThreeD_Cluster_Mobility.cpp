#include<iostream>
#include <cmath>
using namespace std;



int main(){


    int p_x_center = 0;
    int p_y_center = 0;
    int p_z_center = 0;
    int p_x_range, p_y_range, p_z_range, rng;

    cout << "Please Enter The Cluster Range In X Axis\n";
    cin >> p_x_range;
    cout << "Please Enter The Cluster Range In Y Axis\n";
    cin >> p_y_range;
    cout << "Please Enter The Cluster Range In Z Axis\n";
    cin >> p_z_range;
    cout << "Please Enter The Random Range\n";
    cin >> rng;

    cout << "cluster range x, y, z"<<" " << p_x_range<<" " << p_y_range <<" " << p_z_range <<" " << "Random Range"<<" " << rng <<"\n" ;

    cout << "Please Enter The cluster center value of X axis\n";
    cin >> p_x_center;
    cout << "Please Enter The cluster center value of Y axis\n";
    cin >> p_y_center;
    cout << "Please Enter The cluster center value of Z axis\n";
    cin >> p_z_center;

    

    int x_int = (pow(rng,2) - 1) * p_x_range;
    int y_int = (pow(rng,2) - 1) * p_y_range;
    int z_int = (pow(rng,2) - 1) * p_z_range;
    int p_range = 1;

    cout << x_int << " " << y_int << " " << z_int;

    while ((pow(x_int,3) + pow(y_int,3) + pow(z_int,3)) > pow(rng, 3))
    {
        x_int = (pow(rng,2) - 1) * p_x_range;
        y_int = (pow(rng,2) - 1) * p_y_range;
        z_int = (pow(rng,2) - 1) * p_z_range;
    }

    int new_x = x_int + p_x_center;
    int new_y = y_int + p_y_center;
    int new_z = z_int + p_z_center;

    cout << "New position x, y, z"<<" " << new_x<<" " << new_y <<" " << new_z ;

    



    return 0;
}

