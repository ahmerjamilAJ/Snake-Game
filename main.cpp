#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>

using namespace std;

//function to store and output highest scores

void datahandling(int score)
{
    // out stream
    // var dec start
    string name;
    int fscore;
    //var dec end
    cout << "Enter name :  ";
    cin >> name;
    cout << endl;
    fscore = score;
    ofstream storing_data; //NS IS THE VARIABLE TO OUTSTREAM DATA
    storing_data.open("High Score",ios::app);
    storing_data << name << " " << fscore << endl;
    storing_data.close();
    // in streaming
    ifstream recieving_data;
    recieving_data.open("High Score");


    string name_output;
    string name_arry[100];
    string name_arry_topten[10];
    int arry_incrementor =0;
    int score_output;
    int Top_score =0;
    int score_array[100];
    int score_array_topten[10];
    int alpha = 0;
    bool flag = true;








    while(recieving_data >> name_output >> score_output)
    {
        name_arry[arry_incrementor] = name_output;
        score_array[arry_incrementor] = score_output;

        arry_incrementor++;
    }
    cout << "Wait for the high scores" << endl;
    Sleep(5000);

    system("cls");
    //THIS DO WHILE LOOP RUN THE INNER FOR LOOP 3 TIMES
    do
    {
        if (alpha == 2)
        {
            flag = false;
        }
        //THESE LOOPS CALCULATE THE TOP THREE SCORES
        if (alpha == 0)
        {
            int largest = score_array[0];
            string largest_name = name_arry[0];
            for(int i =0; i<arry_incrementor; i++)
            {
                if(score_array[i] > largest)
                {
                    largest = score_array[i];
                    largest_name = name_arry[i];
                    score_array_topten[0] = largest;
                    name_arry_topten[0] = largest_name;
                }

            }

        }

        if(alpha == 1)
        {
            int largest = score_array[0];
            string largest_name = name_arry[0];
            //cout << "working";
            for(int i =0; i<arry_incrementor; i++)
            {
                if(score_array[i] > largest && score_array[i]!=score_array_topten[0])
                {
                    largest = score_array[i];
                    largest_name = name_arry[i];
                    score_array_topten[1] = largest;
                    name_arry_topten[1] = largest_name;
                }

            }
        }

        if(alpha == 2)
        {
            int largest = score_array[0];
            string largest_name = name_arry[0];
            //cout << "working";
            for(int i =0; i<arry_incrementor; i++)
            {
                if(score_array[i] > largest && score_array[i]!=score_array_topten[0] && score_array[i]!=score_array_topten[1])
                {
                    largest = score_array[i];
                    largest_name = name_arry[i];
                    score_array_topten[2] = largest;
                    name_arry_topten[2] = largest_name;
                }

            }
        }

        alpha++;


    }
    while(flag);

    cout << "High scores : "<< endl;
    cout << name_arry_topten[0] << " : " << score_array_topten[0] << endl;
    cout << name_arry_topten[1] << " : " <<score_array_topten[1] << endl;
    cout << name_arry_topten[2] << " : " <<score_array_topten[2] << endl;

}
//THESE NEXT TWO PATCH OF CODES MADE IN VOID WERE PICKED UP FROM THE STACK OVERFLOW
//THERE JOB IS TO JUST CLEAR SCREEN NOTHING ELSE
void clearScreen()

{


    HANDLE hOut;

    COORD Position;



    hOut = GetStdHandle(STD_OUTPUT_HANDLE);



    Position.X = 0;

    Position.Y = 0;

    SetConsoleCursorPosition(hOut, Position);

}





void ShowConsoleCursor(bool showFlag)

{

    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);



    CONSOLE_CURSOR_INFO     cursorInfo;



    GetConsoleCursorInfo(out, &cursorInfo);

    cursorInfo.bVisible = showFlag; // set the cursor visibility

    SetConsoleCursorInfo(out, &cursorInfo);

}

int main()
{
//declaration of variables
    int length=0;
    int x, y, foodX, foodY, score;  // x and y are the points from where the snake starts
    int snakeX[500];
    int snakeY[500];
    int moveto;
    bool running=true;
    const int width = 40;
    const int height = 20;
    int udx= (width+2)/2+2 ;//upper and lower limits of the transportation areas on the top and bottom areas of the map
    int ldx= (width+2)/2-2;
    int udy= (height)/2+2;//upper and lower limits of the transportation areas on the right and left areas of the map
    int ldy= (height)/2-2;
    int deathx[5], deathy[5];//arrays to store x and y locations of the obstructions
    int tp1x,tp1y,tp2x,tp2y;//transportation points
    moveto = -1;
    x = width / 2;
    y = height / 2;
    foodX = rand() % width;
    foodY = rand() % height;
    tp1x = rand() % width;//teleportation points
    tp1y = rand() % height;
    tp2x = rand() % width;
    tp2y =  rand() % height;
    for(int k=0; k<5; k++)//randomly generates position of obstacles
    {
        deathx[k] = rand() % width;
        deathy[k] = rand() % height;
    }

    score = 0;
    //end of declaration of variables

    while(running)//while loop to keep the game running
    {
        clearScreen();//to clear the printed snake and reprint it to a new location and create the effect of a moving snake
        //system("cls");

        //draw
        for (int i = 0; i < width+2; i++)//prints the top boundary of the map
            if(i>=ldx&&i<=udx)
            {
                cout << " ";//leave spaces for the transportation
            }
            else
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole,15);

                cout << "X";//prints boundary
            }
        cout << endl;
        for (int i = 0; i < height; i++)//for loop to print the left and right borders, the transportation points , the obstructions and the snake
        {
            for (int j = 0; j < width; j++)
            {
                if (j == 0 && i<=ldy )
                {
                    cout << "X";//prints boundary
                }
                if (j == 0 && i>=udy)
                {
                    cout << "X";//prints boundary
                }
                if (j == 0 && i>ldy && i<udy )
                {
                    cout << " ";//prints the transportation area
                }
                if (i == y && j == x)
                {
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//color coding
                    SetConsoleTextAttribute(hConsole,11);//color coding
                    cout << "@";//head of the snake
                }
                else if (i == foodY && j == foodX)
                {

                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//color coding
                    SetConsoleTextAttribute(hConsole,2);//color coding

                    cout << "O";//prints food
                }
                else if (i == deathy[0] && j == deathx[0])
                {

                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//color coding
                    SetConsoleTextAttribute(hConsole,4);//color coding

                    cout << "X";//prints obstacles
                }
                else if (i == deathy[1] && j == deathx[1])
                {

                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//color coding
                    SetConsoleTextAttribute(hConsole,4);//color coding

                    cout << "X";//prints obstacles
                }
                else if (i == deathy[2] && j == deathx[2])
                {

                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//color coding
                    SetConsoleTextAttribute(hConsole,4);//color coding

                    cout << "X";//prints obstacles
                }
                else if (i == deathy[3] && j == deathx[3])
                {

                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//color coding
                    SetConsoleTextAttribute(hConsole,4);//color coding

                    cout << "X";//prints obstacles
                }
                else if (i == deathy[4] && j == deathx[4])
                {

                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//color coding
                    SetConsoleTextAttribute(hConsole,4);//color coding

                    cout << "X";//prints obstacles
                }
                else if (i == tp1y && j == tp1x)
                {

                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//color coding
                    SetConsoleTextAttribute(hConsole,9);//color coding

                    cout << "T";//prints teleportation point
                }
                else if (i == tp2y && j == tp2x)
                {

                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//color coding
                    SetConsoleTextAttribute(hConsole,9);//color coding

                    cout << "T";//prints teleportation point
                }
                else
                {
                    int n =2;
                    int check= 1;
                    for (int p = 0; p < length; p++)//prints snake
                    {
                        if(n<=15)//condition to print multicolored snake
                        {
                            n=n+1;
                        }
                        if(n>15)
                        {
                            n=1;
                        }
                        if (snakeX[p] == j && snakeY[p] == i)
                        {
                            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//color coding
                            SetConsoleTextAttribute(hConsole,n);//color coding
                            cout << "O";//prints body of the snake
                            check = 0;
                        }
                    }
                    if (check==1)
                        cout << " ";//prints empty space on the map
                }
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//color coding
                SetConsoleTextAttribute(hConsole,15);//color coding
                if (j == width - 1 && i<=ldy )
                {
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//color coding
                    SetConsoleTextAttribute(hConsole,15);//color coding
                    cout << "X";//prints boundary
                }
                if (j == width - 1 && i>=udy)
                    cout << "X";//prints boundary
                if (j == width - 1 && i>ldy && i<udy )
                    cout << " ";//prints transportation area//empty space to go through

            }
            cout << endl;
        }

        for (int i = 0; i <width+2; i++)
            if(i>=ldx &&i<=udx)
            {
                cout << " ";//prints transportation area//empty space to go through
            }
            else
            {
                cout << "X";//prints lower boundary
            }
        cout << endl;
        cout << "Score:" << score << endl;
//      code to output sounds continuously with the movement of the snake, in sync with the movement
//        if(score<=30)
//        {
//            Beep(659,30-score);
//        }
//        else
//        {
//            Beep(659,1);   //sleep(10);
//        }


        //logic


        int prevX = snakeX[0];
        int prevY = snakeY[0];
        int prev2X, prev2Y;
        snakeX[0] = x;
        snakeY[0] = y;
        if (_kbhit())//condition to check if a key is pressed
        {
            switch (_getch())
            {
            case 'a':
                if (moveto!= 1)
                    moveto = 0;
                break;
            case 'd':
                if (moveto!= 0)
                    moveto = 1;
                break;
            case 'w':
                if (moveto!= 3)
                    moveto = 2;
                break;
            case 's':
                if (moveto!= 2)
                    moveto = 3;
                break;


            }
        }
        switch(moveto)//move the head of the snake in accordance with the key pressed
        {
        case 0:
            x--;
            break;
        case 1:
            x++;
            break;
        case 2:
            y--;
            break;
        case 3:
            y++;
            break;
        default:
            break;
        }
        for (int i = 1; i < length; i++) // this patch of code is to increase the length of the snake and show perfect movement
        {
            prev2X = snakeX[i];
            prev2Y = snakeY[i];
            snakeX[i] = prevX;
            snakeY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }
        if (x > width && y<=ldy+1)//conditions to stop the game if the snake head hits the boundary
        {
            running = false;
        }
        if (x > width && y>=udy-1)
        {
            running = false;
        }
        if (x<0 && y<=ldy)
        {
            running = false;
        }
        if (x<0  && y>=udy)
        {
            running = false;
        }
        if (y>height && x<=ldx-2)
        {
            running = false;
        }
        if(y>height && x>=udx)
        {
            running = false;
        }
        if(y<0&& x>=udx)
        {
            running = false;
        }
        if(y<0&& x<=ldx-2)
        {
            running = false;
        }
        if(x>=width && y>=ldy+1 && y<=udy-1)//move snake head from one transportation area to the other from boundary to boundary
        {

            x = 0;
            Beep(587,20);//output sounds
            Beep(659,20);
            Beep(698,20);
            Beep(784,20);
            //the continuous beeps of various frequencies output a music when the snake teleports
        }
        else if (x<0 && y>=ldy && y<=udy)
        {

            x = width - 1;
            Beep(587,20);
            Beep(659,20);
            Beep(698,20);
            Beep(784,20);
        }
        if(y>=height && x>=ldx-1 && x<=udx-1 )
        {
            y = 0;
            Beep(587,20);
            Beep(659,20);
            Beep(698,20);
            Beep(784,20);
        }
        else if (y<0 && x>=ldx-1 && x<=udx )
        {

            y = height - 1;
            Beep(587,20);
            Beep(659,20);
            Beep(698,20);
            Beep(784,20);
        }
        for(int k=0; k<5; k++)//stop the game of the snake head hits any obstacles/death
        {
            if(y==deathy[k]&& x==deathx[k])
                running = false;
        }
        if(y==tp1y && x==tp1x)//teleport snake from one teleportation point to another
        {
            x=tp2x;
            y=tp2y;
            Beep(587,20);
            Beep(659,20);
            Beep(698,20);
            Beep(784,20);
        }
        else if(y==tp2y && x==tp2x)
        {
            x=tp1x;
            y=tp1y;
            Beep(587,20);
            Beep(659,20);
            Beep(698,20);
            Beep(784,20);
        }

        for(int i = 0; i < length; i++)//stop the game of the snake head hits the snake body
        {

            if (snakeX[i] == x && snakeY[i] == y)
                running = false;

        }
        if (x ==foodX && y==foodY)//when the snake head location is the same as the food's
        {
            cout<<'\a'<<endl;
            score = score + 1;//increment the score
            foodX = rand() % width;//generate new x location for the food
            foodY = rand() % height;//generate new y location for the food
            running = true;
            for(int k=0; k<5; k++)
            {
                deathx[k] = rand() % width;
                deathy[k] = rand() % height;//generate new y locations for the obstacles
            }
            tp1x = rand() % width;//generate new x locations for the teleportation points
            tp1y = rand() % height;//generate new y locations for the teleportation points
            tp2x = rand() % width;
            tp2y =  rand() % height;
            length++;//increment the length of the snake
        }

        if(score<=30)
        {
            Sleep(30-score);//increases the speed of the snake
        }
        else
        {
            Sleep(1);
        }
    }

    Beep(900,50);//outputs a sound when the snake hits the boundary, death/obstacles or itself
    system("cls");//clears the screen to ask for player information and display highest scores
    // data handling
    // out streaming
    datahandling(score);


    return 0;
}
