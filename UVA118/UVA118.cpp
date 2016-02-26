#include<iostream> 
#include<cstring> 
using namespace std;

char buffer[2];
char action[10000];
int bound[2];
int missingPos[10000][2];
int missingNumber = 0;

int direct_c_to_direct_i(char direct_c);
char direct_i_to_direct_c(int direct_i);
bool moves_and_is_missed(int pos[], int direct_i);
int turn(char action, int direct_i);

int main()
{
    cin >> bound[0] >> bound[1];
    int pos[2];
    char direct_c;
    
    while (cin >> pos[0] >> pos[1] >> direct_c) {
        
        int direct_i = direct_c_to_direct_i(direct_c);
        cin.getline(buffer,2);
        cin.getline(action, 10000);
        
        int len = strlen(action);
        
        bool isMissing = false;
        for (int i = 0; i < len; i++) {
            
            if(action[i] == 'F') {
                isMissing = moves_and_is_missed(pos, direct_i);
                if(isMissing) {
                    break;
                }   
            } else if (action[i] == 'R' || action[i] == 'L'){
                direct_i = turn(action[i], direct_i);
            } 
        } 
        
        cout << pos[0] << " " << pos[1] << " " <<direct_i_to_direct_c(direct_i);
        if (isMissing) {
            cout << " LOST";
        }
        cout << endl;
    }

}


int turn(char action, int direct_i) {
    
    if(action == 'R') {
        direct_i ++;
    } else {
        direct_i --;
    }
    if (direct_i > 3) {
        return 0;
    } else if (direct_i < 0) {
        return 3;
    } else {
        return direct_i;
    }
}
    
bool moves_and_is_missed(int pos[2], int direct_i) {
    int new_pos[2];
    int move[4][2] = {
        {0,1}, {1,0}, {0,-1}, {-1,0}
    };
    
    new_pos[0] = pos[0] + move[direct_i][0];
    new_pos[1] = pos[1] + move[direct_i][1];
    
    if ((new_pos[0] <= bound[0] && new_pos[1] <= bound[1]) && (new_pos[0] >= 0 && new_pos[1] >= 0)) {
        pos[0] = new_pos[0];
        pos[1] = new_pos[1];
        return false;
    } else {
        for (int i = 0; i < missingNumber; i++) {
            if( (pos[0] == missingPos[i][0]) && (missingPos[i][1] == pos[1])){
                return false;
            }
        }
        missingPos[missingNumber][0] = pos[0];
        missingPos[missingNumber][1] = pos[1];
        missingNumber ++;
        return true;
    }
}


        
int direct_c_to_direct_i(char direct_c){
    if(direct_c=='N')
        return 0;
    else if(direct_c == 'E')
        return 1;
    else if(direct_c == 'S')
        return 2;
    else 
        return 3;
}

char direct_i_to_direct_c(int direct_i)
{
    char direct[5] = {"NESW"};
    return direct[direct_i];
}
