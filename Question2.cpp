#include <iostream>
#include <math.h>
using namespace std;

struct Point
{
    int x;
    int y;

    Point() {
        x = 0;
        y = 0;
    }

    Point(int x, int y) {
        this->x = x;    // this points to the current object
        this->y = y;
    }

    int getX(){
        return x;
    }

    int getY() {
        return y;
    }

    void setX(int x) {
        this->x = x;
    }

    void setY(int y) {
        this->y = y;
    }

    double dist_bw_pts(Point p) {
        return sqrt(((x - p.x) * (x - p.x)) + ((y - p.y) * (y - p.y)));
    }

    int closest_avg(Point p1, Point p2, Point p3) {
        double distance1 = dist_bw_pts(p1);
        double distance2 = dist_bw_pts(p2);
        double distance3 = dist_bw_pts(p3);

        if(distance1 < distance2 && distance1 < distance3) {
            return 1;   // 1 will be returned incase first average is nearest to the point
        }
        else if(distance2 < distance1 && distance2 < distance3){
            return 2;   // 2 will be returned incase second average is nearest to the point
        }
        else{
            return 3;   // 3 will be returned incase third average is nearest to the point
        }
    }

    Point avg(Point p1, Point p2, Point p3)
    {
        Point p;

        p.x = (p1.x + p2.x + p3.x) / 3;
        p.y = (p1.y + p2.y + p3.y) / 3;

        return p;

    }

    void print()
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    void print_avg(Point p1, Point p2, Point p3)
    {
        Point p = avg(p1, p2, p3);
        
        cout << "(" << p.x << ", " << p.y << ")" << endl;
    }

};

int main()
{
    int pts_tot, avg_tot, x, y;
    Point coordinates[pts_tot];

    cout << "Total number of points: ";
    cin >> pts_tot;

    cout << "Total number of averages: ";
    cin >> avg_tot;

    cout << "Enter the points: " << endl;

    for(int i = 0; i < pts_tot; i++) {
        cout << "Enter the x and y coordinates at point " << i+1 << ": " << endl;
        cin >> x >> y;

        coordinates[i] = Point(x, y);        // Storing in array
    }

    Point avg[avg_tot];

    cout << endl << "Enter the initial averages: " << endl;

    for(int i = 0; i < avg_tot; i++) {
        cout << "Enter the x and y coordinates at average " << i+1 << ": " << endl;
        cin >> x >> y;

        avg[i] = Point(x, y);      // storing in array
    }

    int iterate = 1;

    while(1<2){     // 1<2 is always true so loop will run infinitely
        cout << "Iteration " << iterate << endl;

        int Group1_arr[pts_tot], Group2_arr[pts_tot], Group3_arr[pts_tot];

        /*  Size is set to total number of coordinates because there is a possibility of one group containing all the points
            and other groups containing no points.
        */
        int group1 = 0, group2 = 0, group3 = 0;

        for(int i = 0; i < 8; i++){          // assigning points to nearest average
            int nearest = coordinates[i].closest_avg(avg[0], avg[1], avg[2]);

            if(nearest == 1){
                Group1_arr[group1] = i;
                group1++;
            }
            else if(nearest == 2){
                Group2_arr[group2] = i;
                group2++;
            }
            else{
                Group3_arr[group3] = i;
                group3++;
            }
        }

        cout << "Group 1: ";

        for(int i = 0; i < group1; i++) {
        // running loop for group1 times because group1 is the number of points in group 1
            cout << "(" << coordinates[Group1_arr[i]].x << "," << coordinates[Group1_arr[i]].y << ") ";
        }

        cout << endl;

        cout << "Group 2: ";

        for(int i = 0; i < group2; i++) {
            cout << "(" << coordinates[Group2_arr[i]].x << "," << coordinates[Group2_arr[i]].y << ") ";
        }

        cout << endl;

        cout << "Group 3: ";

        for(int i=0; i<group3; i++) {
            cout << "(" << coordinates[Group3_arr[i]].x << "," << coordinates[Group3_arr[i]].y << ") ";
        }

        Point next_iterate_avg1, next_iterate_avg2, next_iterate_avg3;

        for(int i = 0; i < group1; i++) {
            next_iterate_avg1.x += coordinates[Group1_arr[i]].x;
            next_iterate_avg1.y += coordinates[Group1_arr[i]].y;
        }

        next_iterate_avg1.x = next_iterate_avg1.x / group1;
        next_iterate_avg1.y = next_iterate_avg1.y / group1;

        for(int i = 0; i < group2; i++) {
            next_iterate_avg2.x += coordinates[Group2_arr[i]].x;
            next_iterate_avg2.y += coordinates[Group2_arr[i]].y;
        }

        next_iterate_avg2.x = next_iterate_avg2.x / group2;
        next_iterate_avg2.y = next_iterate_avg2.y / group2;

        for(int i = 0; i < group3; i++) {
            next_iterate_avg3.x += coordinates[Group3_arr[i]].x;
            next_iterate_avg3.y += coordinates[Group3_arr[i]].y;
        }

        next_iterate_avg3.x = next_iterate_avg3.x / group3;
        next_iterate_avg3.y = next_iterate_avg3.y / group3;


        if(next_iterate_avg1.x == avg[0].x && next_iterate_avg1.y == avg[0].y && next_iterate_avg2.x == avg[1].x && next_iterate_avg2.y == avg[1].y && next_iterate_avg3.x == avg[2].x && next_iterate_avg3.y == avg[2].y) {

            cout << endl << "New averages are same as the previous averages." << endl;
            cout << "Hence Averages have been converged at iteration " << iterate << endl;
            break;
        }
        else {

            avg[0] = next_iterate_avg1;
            avg[1] = next_iterate_avg2;
            avg[2] = next_iterate_avg3;

            cout << "The new averages are: " << endl;

            cout << "Average 1: ";
            avg[0].print();

            cout << "Average 2: ";
            avg[1].print();

            cout << "Average 3: ";
            avg[2].print();
        }

        iterate++;

    }

    return 0;
}
