#include<bits/stdc++.h>

struct carpet_attributes{
    int leftbottomposition[2]; // {x, y}
    int righttopposition[2]; // {x, y}
    int x_length; // the value of width
    int y_length; // the value of height
};

int main(){
    // Step 1: Prepare all values
    int carpet_number; // the number of carpet
    std::cin >> carpet_number;
    carpet_attributes carpet[carpet_number]; // arrays to store attributes of carpets

    for (int i = 0; i < carpet_number; i++)
    {
        carpet_attributes temp_carpet; // temporary struct object
        std::cin >> temp_carpet.leftbottomposition[0] >> temp_carpet.leftbottomposition[1] // get attributes of your catpet from input(x and y)
            >> temp_carpet.x_length >> temp_carpet.y_length; // get attributes of your catpet from input(width and height)
        temp_carpet.righttopposition[0] = temp_carpet.leftbottomposition[0] + temp_carpet.x_length; // set x of right top corner
        temp_carpet.righttopposition[1] = temp_carpet.leftbottomposition[1] + temp_carpet.y_length; // set y of right top corner
        carpet[i] = temp_carpet; // put into carpet[] and prepare for use
    }
    
    int pointposition[2]; // point position
    std::cin >> pointposition[0] >> pointposition[1];

    // Step 2: Which carpet is this point in?
    int po = -1; // store the result(carpet number), default -1 if there is no eligible carpet
    for (int i = 0; i < carpet_number; i++)
    {
        int leftbottom[2] = {carpet[i].leftbottomposition[0], carpet[i].leftbottomposition[1]}; // take out the object
        int righttop[2] = {carpet[i].righttopposition[0], carpet[i].righttopposition[1]}; // take out the object
        if (pointposition[0] >= leftbottom[0] // comparing with left bottom corner(width)
        && pointposition[1] >= leftbottom[1] // comparing with left bottom corner(height)
        && pointposition[0] <= righttop[0] // comparing with right top corner(width)
        && pointposition[1] <= righttop[1]) // comparing with right top corner(height)
            {
                po = i + 1; // we must +1 because actual value is bigger than index value
            }   
    }
    std::cout << po; // output result
    return 0;
}
