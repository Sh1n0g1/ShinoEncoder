#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int shinodecode(char *s, char *output){
	//s			string to be decoded
	//output	return result
	int cnt=0;
	output[0]=0;
	for(int i=0; i < strlen(s); i++){
		if(	s[i] >= 0x30 && s[i] <= 0x39 ||  	//0-9
			s[i] >= 0x41 && s[i] <= 0x5A ||		//A-Z
			s[i] >= 0x61 && s[i] <= 0x7a		//a-z	
		){
			printf("%c",s[i]);
			output[cnt]++;
		}else{
			if(output[cnt] != 0){
				cnt++;
				output[cnt]=0;
			}
		}
	}
	
	for(int j=0; j < cnt/2 +1; j++){
		output[j]=(output[j*2]-2)*16+output[j*2+1]-2;
	}
	output[cnt/2+1]=0;
	return cnt;
}

void banner(){
	printf("\n");
	printf("       8       o                   8                           8        \n");
	printf("       8                           8                           8        \n");
	printf(".oPYo. 8oPYo. o8 odYo. .oPYo. .oPYo8 .oPYo. .oPYo. .oPYo. .oPYo8 .oPYo. \n");
	printf("Yb..   8    8  8 8' `8 8    8 8    8 8oooo8 8    ' 8    8 8    8 8oooo8 \n");
	printf("  'Yb. 8    8  8 8   8 8    8 8    8 8.     8    . 8    8 8    8 8.     \n");
	printf("`YooP' 8    8  8 8   8 `YooP' `YooP' `Yooo' `YooP' `YooP' `YooP' `Yooo' \n");
	printf("                                                            			\n");
	printf("                                                            ver.1.0.0.0 \n");
	printf("\n");
}


int main(int argc, char *argv[]){
	
	char buf[2048];
	int s;
	if(argc < 2){
		banner();
		printf("\nusage: ShinoDecode \"string\" \n");
		return -1;
	}else if(argc > 2){
		banner();
		printf("\nusage: ShinoDecode \"string\" \n\nYou are maybe forgetting the double quote(\").\ne.g) ShinoDecode \"Hello There\"");
	}else{
		s=shinodecode(argv[1],buf);
		if(s != 0){
			printf("%s",buf);
		}
		return 0;
	}
}
