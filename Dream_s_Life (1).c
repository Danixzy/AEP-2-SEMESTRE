#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.c>
#include <time.h>
#include <ctype.h>
#include <locale.h>

char parada,nome[50];
int cont;

int main(){
  
  
  setlocale(LC_ALL,"portuguese");	

  CONSOLE_CURSOR_INFO cursor = {1,FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
  menu();
  return(0);
}

//-----------------------------------------------------------------------------    

void menu(){ 

textcolor(15);
textbackground(0);
system("cls");

int op=1; 
char tecla;
 do{  
   textcolor(15);
   textbackground(0);
   
   gotoxy(46,9);  printf("=====================");
   gotoxy(51,10); printf("DREAM�S LIFE");
   gotoxy(46,11); printf("=====================");
   gotoxy(50,13); printf(" Jogar        ");
   gotoxy(50,14); printf(" Instru��es   ");
   gotoxy(50,15); printf(" Cr�ditos     ");
   gotoxy(50,16); printf(" Sair do jogo ");
   
   textcolor(4);
   textbackground(15);
   
   switch (op){
      case 1: 
         gotoxy(50,13); printf(" Jogar        ");      
         break;
      case 2:
         gotoxy(50,14); printf(" Instru��es   ");      
         break;
      case 3:
         gotoxy(50,15); printf(" Cr�ditos     ");      
         break; 
      case 4:
         gotoxy(50,16); printf(" Sair do jogo ");      
         break; 
          
    }
    
    tecla=getch();  
    if (tecla<0)
      tecla=getch();
    
    
    switch (tecla){
       case 119:  //pra cima
        if (op-1>=1)
             op--; 
         else
             op=4; 
             
         break;    
       case 115:  //pra baixo
         if (op+1<=4)
             op++;
             else
             op=1;
         break;
       case 13: //ENTER
         switch (op){
            case 1:
                 jogar();   
                 break;
            case 2:
                 instrucoes();
                 break;
            case 3:
                 creditos();
                 break;
            case 4:
                 tecla=27; //ESC
                 break;                    
                }
                             
         break;                
           
    }  
  } 
  while (tecla!=27); //ESC 
}  

//-----------------------------------------------------------------------------   

void jogar(){
	
   textcolor(0);
   textbackground(6);
   system("cls");
   gotoxy(44,11); printf("============================");
   gotoxy(48,12); printf("ESCOLHA A DIFICULDADE ");
   gotoxy(44,13); printf("============================");
   
int op=1; 
char tecla;

 do{  
   textcolor(0);
   textbackground(6);
   
   gotoxy(52,15); printf(" F�cil    ");
   gotoxy(52,16); printf(" M�dio    ");
   gotoxy(52,17); printf(" Dificil  ");
   textbackground(0);
   textcolor(15);
   gotoxy(9,25); printf(" Voltar  ");
   
   textcolor(0);
   textbackground(15);
   
   switch (op){
      case 1:
         gotoxy(52,15); printf(" F�cil   ");      
         break;
      case 2:
         gotoxy(52,16); printf(" M�dio   ");      
         break; 
      case 3:
         gotoxy(52,17); printf(" Dif�cil ");      
         break; 
      case 4:
     	 gotoxy(9,25);  printf(" Voltar  ");      
         break; 
          
    }
    
    tecla=getch();  
    if (tecla<0)
      tecla=getch();
    
    
    switch (tecla){
       case 119:  //pra cima
        if (op-1>=1)
             op--; 
         else
             op=4; 
             
         break;    
       case 115:  //pra baixo
         if (op+1<=4)
             op++;
             else
             op=1;
         break;
       case 13: //ENTER
         switch (op){
            case 1:
                 jogoFacil();  
                 break;
            case 2:
                 jogoMedio();
                 break;
            case 3:
                 jogoDificil();
                 break;
            case 4:
                 menu(); 
                 break;                  
                }
                             
         break;                
           
    }  
  } 
  while (tecla !=27);

    
  textbackground(0);
  system("cls");
   
}

//----------------------------------------------------------------------------- 

void instrucoes(){
	
 textbackground(15);
 textcolor(5);
 system("cls");
 gotoxy(52,8); printf("INSTRU��ES");
 gotoxy(17,11); printf("===================================================================================");
 gotoxy(26,13); printf("Dream�s life � um jogo de m�ltiplas escolhas,                     ");
 gotoxy(26,14); printf("onde o objetivo � se tornar bem sucedido em sua vida.             ");
 gotoxy(26,15); printf("Voc� enfretar� diversas dificulades, tendo que pensar e raciocinar");
 gotoxy(26,16); printf("qual a escolha certa a se fazer.");
 gotoxy(26,17); printf("Cada escolha influenciar� em sua vida pessoal ou profissional,    ");
 gotoxy(26,18); printf("caso feita a escolha errada, poder� acarretar");
 gotoxy(26,19); printf("em um problema futuro ou presente,");
 gotoxy(26,20); printf("por isso pense bem antes de fazer qualquer escolha. ");
 gotoxy(17,22);	printf("==================================================================================");

 parada=getch();
 textbackground(0);
 system("cls");	
		
	
}

//-----------------------------------------------------------------------------    

void creditos(){
	
   textbackground(4);
   textcolor(0);
   system("cls");
   gotoxy(45,12); printf("       C R � D I T O S");
   gotoxy(45,13); printf("      Unicesumar - 2023");
   gotoxy(39,15); printf("Jogo desenvolvido por alunos da ESOFT-2S-N-B");
   gotoxy(46,16); printf("      Leonardo F�varo           ");
   gotoxy(45,17); printf("   Daniel Andrade Mendon�a      ");
   gotoxy(45,18); printf("Vinicius Pietracatella da Silva ");
   parada=getch();
   textbackground(0);
   system("cls");
        
}
//-----------------------------------------------------------------------------   

void sucesso(){
	
   textbackground(4);
   textcolor(0);
   system("cls");
   gotoxy(26,16); printf("Voce conseguiu ser bem sucedido em sua vida profissional, parab�ns %s.",nome);
   parada=getch();
   textbackground(0);
   system("cls");

}

//-----------------------------------------------------------------------------

void derrota(){
	
   textbackground(4);
   textcolor(0);
   system("cls");
   gotoxy(37,16); printf("Voce perdeu, continuar� pobre o resto da vida");
   parada=getch();
   textbackground(0);
   system("cls");

}
//----------------------------------------------------------------------------- 

void jogoFacil(){
	
	cont = 1;
	
    textbackground(4);
   textcolor(0);
   system("cls");
   gotoxy(41,4);  printf("-------Bem-Vindo ao Dream�s Life--------");
   gotoxy(31,14); printf("===============================================================");
   gotoxy(44,15); printf("Voc� escolheu a dificuldade f�cil");
   gotoxy(33,16); printf("Para jogadores que querem uma experi�ncia sem muito raciocinio");
   gotoxy(44,17); printf("focando mais na hist�ria do jogo");
   gotoxy(31,18); printf("===============================================================");
   
   int op=1; 
char tecla;

 do{  
   textcolor(15);
   textbackground(0);
   
   gotoxy(32,23); printf("  Voltar  ");
   gotoxy(80,23); printf(" Continuar ");

   textcolor(0);
   textbackground(15);
   
   switch (op){
   	  case 1: 
   	  	gotoxy(32,23); printf("  Voltar  ");
   	  	break;
      case 2:
         gotoxy(80,23); printf(" Continuar ");      
         break;
   
          
    }
    
    tecla=getch();  
    if (tecla<0)
      tecla=getch();
    
    
    switch (tecla){
       case 119:  //pra cima
        if (op-1>=1)
             op--; 
         else
             op=2; 
             
         break;    
       case 115:  //pra baixo
         if (op+1<=2)
             op++;
             else
             op=1;
         break;
       case 13: //ENTER
         switch (op){
         	case 1:
                 jogar();  
                 break;
            case 2:
                 login();  
                 break;                
                }
                             
         break;                
           
    }  
  } 
  while (tecla !=27);

    
  textbackground(0);
  system("cls");
   parada=getch();
   
}
//----------------------------------------------------------------------------- 

void login(){
	
   textbackground(4);
   textcolor(0);
   system("cls");
   gotoxy(52,10); printf("===============");
   gotoxy(52,11); printf("|    LOGIN    |");
   gotoxy(52,12); printf("===============");
   
   textbackground(15);
   textcolor(0);
   gotoxy(45,16); printf("-------------------------------");
   gotoxy(45,17); printf("| Informe seu nome de usu�rio |");
   gotoxy(45,18); printf("-------------------------------");
   gotoxy(56,20); scanf ("%s",&nome);

   escolhaProfissao();
	
}

//----------------------------------------------------------------------------- 

void escolhaProfissao(){
	
   textcolor(0);
   textbackground(4);
   system("cls");
   gotoxy(44,11); printf("===============================");
   gotoxy(48,12); printf("ESCOLHA A SUA PROFISS�O ");
   gotoxy(44,13); printf("===============================");
   
int op=1; 
char tecla;

 do{  
   textcolor(0);
   textbackground(4);
   
   gotoxy(45,15); printf("           Lixeiro            ");
   gotoxy(45,16); printf("   Desenvolvedor de Software  ");
   gotoxy(45,17); printf("          Empresario          ");
   
   textcolor(0);
   textbackground(15);
   
   switch (op){
      case 1:
         gotoxy(45,15); printf("           Lixeiro            ");
         break;
      case 2:
         gotoxy(45,16); printf("   Desenvolvedor de Software  ");      
         break; 
      case 3:
         gotoxy(45,17); printf("          Empresario          ");      
         break; 
          
    }
    
    tecla=getch();  
    if (tecla<0)
      tecla=getch();
    
    
    switch (tecla){
       case 119:  //pra cima
        if (op-1>=1)
             op--; 
         else
             op=3; 
             
         break;    
       case 115:  //pra baixo
         if (op+1<=3)
             op++;
             else
             op=1;
         break;
       case 13: //ENTER
         switch (op){
            case 1:
                 lixeiro();  
                 break;
            case 2:
                 desenvolvedor();
                 break;
            case 3:
                 empresario();
                 break;
            case 4:
                 tecla=27; 
                 break;                  
                }
                             
         break;                
           
    }  
  } 
  while (tecla !=27);

    
  textbackground(0);
  system("cls");
   
}
//----------------------------------------------------------------------------- 

void lixeiro(){
	
	  textcolor(0);
   textbackground(4);
   system("cls");
   gotoxy(30,11); printf("===============================================================");
   gotoxy(30,12); printf("Voc� escolheu o trabalho de lixeiro, o sal�rio � de R$ 1500,00, ");
   gotoxy(30,13); printf("sendo que, a carga hor�ria � de 6 horas por dia. A prefeitura te");
   gotoxy(30,14); printf("oferta uma proposta para trabalhar de motorisa de caminh�o de lixo,"); 
   gotoxy(30,15); printf("com um sal�rio de R$ 2500,00, por�m trabalhando 8 horas di�rias.");
   gotoxy(53,16); printf("voce aceita %s? ",nome);
   gotoxy(30,17); printf("===============================================================");
   
int op=1; 
char tecla;

 do{  
   textcolor(0);
   textbackground(4);
   
   gotoxy(57,19); printf("  Sim  ");
   gotoxy(57,20); printf("  N�o  ");
   
   textcolor(0);
   textbackground(15);
   
   switch (op){
      case 1:
         gotoxy(57,19); printf("  Sim  ");      
         break;
      case 2:
         gotoxy(57,20); printf("  N�o  ");      
         break; 
          
    }
    
    tecla=getch();  
    if (tecla<0)
      tecla=getch();
    
    
    switch (tecla){
       case 119:  //pra cima
        if (op-1>=1)
             op--; 
         else
             op=2; 
             
         break;    
       case 115:  //pra baixo
         if (op+1<=2)
             op++;
             else
             op=1;
         break;
       case 13: //ENTER
         switch (op){
            case 1:
                 motorista();  
                 break;
            case 2:
                 derrota();
                 break;
            case 3:
                 tecla=27; 
                 break;                  
                }
                             
         break;                
           
    }  
  } while (tecla !=27);

    
  textbackground(0);
  system("cls");
   
}

//-----------------------------------------------------------------------------    

void motorista(){
	
    textcolor(0);
   textbackground(4);
   system("cls");
   gotoxy(30,11); printf("===============================================================");
   gotoxy(30,12); printf("A prefeitura gostou muito do seu trabalho, por isso resolveram ");
   gotoxy(30,13); printf("te ofertar uma proposta para trabalhar como motorista particular do prefeito,");
   gotoxy(30,14); printf("por�m ser� preciso ter disponibilidade a qualque hor�rio.");
   gotoxy(30,15); printf("O sal�rio pago ser� de R$ 5000,00.");
   gotoxy(53,16); printf("Voc� aceita %s? ",nome);
   
   gotoxy(30,17); printf("===============================================================");
   
int op=1; 
char tecla;

 do{  
   textcolor(0);
   textbackground(4);
   
   gotoxy(57,19); printf("  Sim ");
   gotoxy(57,20); printf("  N�o  ");

   
   textcolor(0);
   textbackground(15);
   
   switch (op){
      case 1:
         gotoxy(57,19); printf("  Sim  ");      
         break;
      case 2:
         gotoxy(57,20); printf("  N�o  ");      
         break; 
          
    }
    
    tecla=getch();  
    if (tecla<0)
      tecla=getch();
    
    
    switch (tecla){
       case 119:  //pra cima
        if (op-1>=1)
             op--; 
         else
             op=2; 
             
         break;    
       case 115:  //pra baixo
         if (op+1<=2)
             op++;
             else
             op=1;
         break;
       case 13: //ENTER
         switch (op){
            case 1:
                 corno();  
                 break;
            case 2:
                 derrota();
                 break;
            case 3:
                 tecla=27; 
                 break;                  
                }
                             
         break;                
           
    }  
  } 
  while (tecla !=27);

    
  textbackground(0);
  system("cls");

}

//-----------------------------------------------------------------------------
void corno(){
	
    textcolor(0);
   textbackground(4);
   system("cls");
   gotoxy(30,11); printf("===============================================================");
   gotoxy(30,12); printf("Voce come�ou a ter um romance com a faxineira do prefeito, e em");
   gotoxy(30,13); printf("2 meses voce descobriu que foi corno, logo em seguida se afundou");
   gotoxy(30,14); printf("nas bebidas alcolicas, foi demitido e perdeu tudo o que tinha");
   gotoxy(30,16); printf("===============================================================");
   
int op=1; 
char tecla;

 do{  
   textcolor(0);
   textbackground(4);
   
   gotoxy(53,18); printf(" Continuar  ");

   
   textcolor(0);
   textbackground(15);
   
   switch (op){
      case 1:
         gotoxy(53,18); printf(" Continuar ");      
         break;
   
          
    }
    
    tecla=getch();  
    if (tecla<0)
      tecla=getch();
      
    if (cont == 2 || cont == 3){
        switch (tecla){
       case 119:  //pra cima
        if (op-1>=1)
             op--; 
         else
             op=2; 
             
         break;    
       case 115:  //pra baixo
         if (op+1<=2)
             op++;
             else
             op=1;
         break;
       case 13: //ENTER
         switch (op){
            case 1:
                 lixeiroMedio();  
                 break;
            case 2:
                 derrota();
                 break;    
   	    }
   }
	}else{
    switch (tecla){
       case 119:  //pra cima
        if (op-1>=1)
             op--; 
         else
             op=2; 
             
         break;    
       case 115:  //pra baixo
         if (op+1<=2)
             op++;
             else
             op=1;
         break;
       case 13: //ENTER
         switch (op){
            case 1:
                 sucesso();  
                 break;
            case 2:
                 derrota();
                 break;               
           
    }  
  } 
}
 }while (tecla !=27);
    
  textbackground(0);
  system("cls");

}
//----------------------------------------------------------------------------- 

void desenvolvedor(){
	
	textcolor(0);
   textbackground(4);
   system("cls");
   gotoxy(30,11); printf("===================================================================");
   gotoxy(30,12); printf("DB1 te ofereceu uma vaga de trainee ganhando 1200 reais no mes ");
   gotoxy(30,13); printf("trabalhando de meio periodo, das 7 da manha ate as 11 e 40 da manha");
   gotoxy(53,14); printf("voce aceita %s? ",nome);
   gotoxy(30,15); printf("===================================================================");
   
int op=1; 
char tecla;

 do{  
   textcolor(0);
   textbackground(4);
   
   gotoxy(57,17); printf(" Sim  ");
   gotoxy(57,18); printf(" N�o  ");

   textcolor(0);
   textbackground(15);
   
   switch (op){
      case 1:
         gotoxy(57,17); printf(" Sim  ");      
         break;
      case 2:
         gotoxy(57,18); printf(" N�o  ");      
         break; 
  
          
    }
    
    tecla=getch();  
    if (tecla<0)
      tecla=getch();
    
    
    switch (tecla){
       case 119:  //pra cima
        if (op-1>=1)
             op--; 
         else
             op=2; 
             
         break;    
       case 115:  //pra baixo
         if (op+1<=2)
             op++;
             else
             op=1;
         break;
       case 13: //ENTER
         switch (op){
            case 1:
                 DB1();  
                 break;
            case 2:
                 derrota();
                 break;
                             
         break;                
           
    }  
  }
  
  }while (tecla !=27);

    
  textbackground(0);
  system("cls");
	
 
 
}

//-----------------------------------------------------------------------------     

void DB1(){
	
    textcolor(0);
   textbackground(4);
   system("cls");
   gotoxy(30,11); printf("================================================================");
   gotoxy(32,12); printf("Dentro da DB1 te oferecem uma vaga de periodo integral para ");
   gotoxy(32,13); printf("Trabalhar na parte back-end em um sistema de linguagem phtyon");
   gotoxy(32,14); printf("ganhando R$ 5000,00 reais");
   gotoxy(53,15); printf("Voc� aceita %s? ",nome);
   gotoxy(30,16); printf("===============================================================");
   
int op=1; 
char tecla;

 do{  
   textcolor(0);
   textbackground(4);
   
   gotoxy(57,17); printf("  Sim  ");
   gotoxy(57,18); printf("  N�o  ");
  
   
   textcolor(0);
   textbackground(15);
   
   switch (op){
      case 1:
         gotoxy(57,17); printf("  Sim  ");      
         break;
      case 2:
         gotoxy(57,18); printf("  N�o  ");      
         break; 
    
          
    }
    
    
    tecla=getch();  
    if (tecla<0)
      tecla=getch();
    
    if (cont == 2 || cont == 3){
        switch (tecla){
       case 119:  //pra cima
        if (op-1>=1)
             op--; 
         else
             op=2; 
             
         break;    
       case 115:  //pra baixo
         if (op+1<=2)
             op++;
             else
             op=1;
         break;
       case 13: //ENTER
         switch (op){
            case 1:
                 desenvolvedorMedio();  
                 break;
            case 2:
                 derrota();
                 break;    
   	    }
   }
	}else{
    switch (tecla){
       case 119:  //pra cima
        if (op-1>=1)
             op--; 
         else
             op=2; 
             
         break;    
       case 115:  //pra baixo
         if (op+1<=2)
             op++;
             else
             op=1;
         break;
       case 13: //ENTER
         switch (op){
            case 1:
                 sucesso();  
                 break;
            case 2:
                 derrota();
                 break;               
           
    }  
  } 
}
 }while (tecla !=27);

    
  textbackground(0);
  system("cls");


}

//-----------------------------------------------------------------------------

void empresario(){
	
   	
	  textcolor(0);
   textbackground(4);
   system("cls");
   gotoxy(28,11); printf("======================================================================");
   gotoxy(30,12); printf("Voc� nao possuia nada, e seu pai tinha fugido de voce, seu pai ");
   gotoxy(30,13); printf("veio a falecer e agora voce � um herdeiro de uma empresa milionaria");
   gotoxy(30,14); printf("multinacional, e quer aproveitar a vida de milionario.");
   gotoxy(30,15); printf("Voc� deseja sair festejando por ai ou continuar com seu namoro");
   gotoxy(30,16); printf("com a pessoa amada, e cuidar da empresa?");
   gotoxy(28,17); printf("======================================================================");
   
int op=1; 
char tecla;

 do{  
   textcolor(0);
   textbackground(4);
   
   gotoxy(40,19); printf(" Sair festejando por ai ");
   gotoxy(40,20); printf(" Cuidar da empresa e criar uma familia  ");
  
   textcolor(0);
   textbackground(15);
   
   switch (op){
      case 1:
         gotoxy(40,19); printf(" Sair festejando por ai ");      
         break;
      case 2:
         gotoxy(40,20); printf(" Cuidar da empresa e criar uma familia  ");      
         break; 
          
    }
    
    tecla=getch();  
    if (tecla<0)
      tecla=getch();
    
    
    switch (tecla){
       case 119:  //pra cima
        if (op-1>=1)
             op--; 
         else
             op=2; 
             
         break;    
       case 115:  //pra baixo
         if (op+1<=2)
             op++;
             else
             op=1;
         break;
       case 13: //ENTER
         switch (op){
            case 1:
                 derrota();  
                 break;
            case 2:
                 familia();
                 break;
         
    }  
  } 
 } while (tecla !=27);

    
  textbackground(0);
  system("cls");
  
}

//----------------------------------------------------------------------------- 
void familia(){
	
    textcolor(0);
   textbackground(4);
   system("cls");
   gotoxy(28,11); printf("=========================================================================");
   gotoxy(30,12); printf("Voc� esta noivo, sua mulher esta gravida, e o gerente precisa cuidar da");
   gotoxy(30,13); printf("empresa. O mesmo recebeu uma oferta melhor de outra empresa e a aceitou.");
   gotoxy(30,14); printf("Voc� tem duas op��es, contratar um novo gerente ou ");
   gotoxy(30,15); printf("deixar a familia de lado e assumir a empresa novamente. ");
   gotoxy(45,16); printf("Qual a sua decis�o?");
   gotoxy(28,17); printf("=========================================================================");
   
int op=1; 
char tecla;

 do{  
   textcolor(0);
   textbackground(4);
   
   gotoxy(50,19); printf(" Contratar outro Gerente ");
   gotoxy(50,20); printf(" Assumir a empresa ");
   
   textcolor(0);
   textbackground(15);
   
   switch (op){
      case 1:
         gotoxy(50,19); printf(" Contratar outro Gerente ");      
         break;
      case 2:
     	 gotoxy(50,20);  printf(" Assumir a empresa ");      
         break; 

          
    }
    
        tecla=getch();  
    if (tecla<0)
      tecla=getch();
    
   
    if (cont == 2 || cont == 3){
        switch (tecla){
       case 119:  //pra cima
        if (op-1>=1)
             op--; 
         else
             op=2; 
             
         break;    
       case 115:  //pra baixo
         if (op+1<=2)
             op++;
             else
             op=1;
         break;
       case 13: //ENTER
         switch (op){
            case 1:
                 derrota();  
                 break;
            case 2:
                 empresarioMedio();
                 break;    
   	    }
   }
	}else{
    switch (tecla){
       case 119:  //pra cima
        if (op-1>=1)
             op--; 
         else
             op=2; 
             
         break;    
       case 115:  //pra baixo
         if (op+1<=2)
             op++;
             else
             op=1;
         break;
       case 13: //ENTER
         switch (op){
            case 1:
                 sucesso();  
                 break;
            case 2:
                 derrota();
                 break;               
           
    }  
   } 
  }
 }while (tecla !=27);

    
  textbackground(0);
  system("cls");

  
}

//-----------------------------------------------------------------------------    
void jogoMedio(){
	
	cont = 2;
	
   textbackground(4);
   textcolor(0);
   system("cls");
   gotoxy(41,4);  printf("-------Bem-Vindo ao Dream�s Life--------");
   gotoxy(31,14); printf("===============================================================");
   gotoxy(44,15); printf("Voc� escolheu a dificuldade m�dia");
   gotoxy(33,16); printf("Para jogadores que querem uma experi�ncia mais balanceada");
   gotoxy(44,17); printf("Tanto na hist�ria quanto em racioc�nio");
   gotoxy(31,18); printf("===============================================================");
   
   int op=1; 
char tecla;

 do{  
   textcolor(15);
   textbackground(0);
   
   gotoxy(32,23); printf("   Voltar   ");
   gotoxy(80,23); printf(" Continuar ");

   textcolor(0);
   textbackground(15);
   
   switch (op){
   	  case 1: 
   	  	gotoxy(32,23); printf("   Voltar   ");
   	  	break;
      case 2:
         gotoxy(80,23); printf(" Continuar ");      
         break;
   
          
    }
    
    tecla=getch();  
    if (tecla<0)
      tecla=getch();
    
    
    switch (tecla){
       case 119:  //pra cima
        if (op-1>=1)
             op--; 
         else
             op=2; 
             
         break;    
       case 115:  //pra baixo
         if (op+1<=2)
             op++;
             else
             op=1;
         break;
       case 13: //ENTER
         switch (op){
         	case 1:
                 jogar();  
                 break;
            case 2:
                 login();  
                 break;              
           
    }  
  } 
 } while (tecla !=27);

    
  textbackground(0);
  system("cls");
   parada=getch();
}
//-----------------------------------------------------------------------------  

void lixeiroMedio(){
	
	
	 textcolor(0);
   textbackground(4);
   system("cls");
   gotoxy(30,11); printf("===============================================================");
   gotoxy(30,12); printf("Depois desse infeliz acontecimento sua condi��o de vida piorou.");
   gotoxy(30,13); printf("Foi preciso voltar a casa de sua m�e, buscar ajuda para se resta-");
   gotoxy(30,14); printf("belecer financeiramente. Coincidentemente seu tio estava precisando");
   gotoxy(30,15); printf("de m�o de obra na lavoura e te chamou para trabalhar.");
   gotoxy(30,16); printf("Voc� aceita a proposta %s?",nome);
   gotoxy(30,17); printf("===============================================================");
   
int op=1; 
char tecla;

 do{  
   textcolor(0);
   textbackground(4);
   
   gotoxy(57,19); printf("  Sim  ");
   gotoxy(57,20); printf("  N�o  ");

   
   textcolor(0);
   textbackground(15);
   
   switch (op){
      case 1:
         gotoxy(57,19); printf("  Sim  ");   
         break;
      	case 2:
      		 gotoxy(57,20); printf("  N�o  ");
      		 break;
   
          
    }
    
    tecla=getch();  
    if (tecla<0)
      tecla=getch();
       
    
    if (cont == 3){
        switch (tecla){
       case 119:  //pra cima
        if (op-1>=1)
             op--; 
         else
             op=2; 
             
         break;    
       case 115:  //pra baixo
         if (op+1<=2)
             op++;
             else
             op=1;
         break;
       case 13: //ENTER
         switch (op){
            case 1:
                 lixeiroDificil();  
                 break;
            case 2:
                 derrota();
                 break;    
   	    }
   }
	}else{
    switch (tecla){
       case 119:  //pra cima
        if (op-1>=1)
             op--; 
         else
             op=2; 
             
         break;    
       case 115:  //pra baixo
         if (op+1<=2)
             op++;
             else
             op=1;
         break;
       case 13: //ENTER
         switch (op){
            case 1:
                 sucesso();  
                 break;
            case 2:
                 derrota();
                 break;               
           
    }  
  } 
}
 }while (tecla !=27);

    
  textbackground(0);
  system("cls");
	
	
	
}  
//-----------------------------------------------------------------------------    

void desenvolvedorMedio(){
	
	
	textcolor(0);
   textbackground(4);
   system("cls");
   gotoxy(30,11); printf("===============================================================");
   gotoxy(30,12); printf("Passaram-se alguns anos de sua promo��o na DB1 e voc� n�o");
   gotoxy(30,13); printf("est� mais satisfeito com o sal�rio. A empresa est� em deca-");
   gotoxy(30,14); printf("d�ncia e n�o pode te dar um aumento ou promo��o.");
   gotoxy(30,15); printf("Voc� recebeu uma proposta da empresa Matera.");
   gotoxy(30,16); printf("Voc� aceita a proposta %s?",nome);
   gotoxy(30,17); printf("===============================================================");
   
int op=1; 
char tecla;

 do{  
   textcolor(0);
   textbackground(4);
   
   gotoxy(57,19); printf("  Sim  ");
   gotoxy(57,20); printf("  N�o  ");

   
   textcolor(0);
   textbackground(15);
   
   switch (op){
      case 1:
         gotoxy(57,19); printf("  Sim  ");   
         break;
      	case 2:
      		 gotoxy(57,20); printf("  N�o  ");
      		 break;
   
          
    }
    
    tecla=getch();  
    if (tecla<0)
      tecla=getch();
      
 
    if (cont == 3){
        switch (tecla){
       case 119:  //pra cima
        if (op-1>=1)
             op--; 
         else
             op=2; 
             
         break;    
       case 115:  //pra baixo
         if (op+1<=2)
             op++;
             else
             op=1;
         break;
       case 13: //ENTER
         switch (op){
            case 1:
                 desenvolvedorDificil();  
                 break;
            case 2:
                 derrota();
                 break;    
   	    }
   }
	}
	else{
    switch (tecla){
       case 119:  //pra cima
        if (op-1>=1)
             op--; 
         else
             op=2; 
             
         break;    
       case 115:  //pra baixo
         if (op+1<=2)
             op++;
             else
             op=1;
         break;
       case 13: //ENTER
         switch (op){
            case 1:
                 sucesso();  
                 break;
            case 2:
                 derrota();
                 break;               
           
    }  
   } 
  }
} while (tecla !=27);

    
  textbackground(0);
  system("cls");
		
}

//-----------------------------------------------------------------------------    

void empresarioMedio(){
	
		
	textcolor(0);
   textbackground(4);
   system("cls");
   gotoxy(30,11); printf("================================================================");
   gotoxy(30,12); printf("Parab�ns, a sua empresa prosperou, por�m para isso foi preciso");
   gotoxy(30,13); printf("se afastar de sua familia para focar no trabalho, seu relaciona-");
   gotoxy(30,14); printf("mento com a sua esposa j� n�o � mais o mesmo de antes.");
   gotoxy(30,15); printf("Voc� esta correndo risco de sua esposa te deixar e");
   gotoxy(30,16); printf("viver uma vida solit�ria, h� duas op��es:");
   gotoxy(30,17); printf("Tirar f�rias e aproveitar o tempo com a fam�lia.");
   gotoxy(30,18); printf("Abrir uma franquia da sua empresa e prosperar ainda mais.");
   gotoxy(30,19); printf("Voc� aceita a proposta %s?",nome);
   gotoxy(30,20); printf("================================================================");
   
int op=1; 
char tecla;

 do{  
   textcolor(0);
   textbackground(4);
   
   gotoxy(53,22); printf("  Tirar f�rias  ");
   gotoxy(53,23); printf("  Abrir franquia  ");

   
   textcolor(0);
   textbackground(15);
   
   switch (op){
      case 1:
         gotoxy(53,22); printf("  Tirar f�rias  ");   
         break;
      	case 2:
      		 gotoxy(53,23); printf("  Abrir franquia  ");
      		 break;
   
          
    }
    
    tecla=getch();  
    if (tecla<0)
      tecla=getch();
       
    
  
    if (cont == 3){
        switch (tecla){
       case 119:  //pra cima
        if (op-1>=1)
             op--; 
         else
             op=2; 
             
         break;    
       case 115:  //pra baixo
         if (op+1<=2)
             op++;
             else
             op=1;
         break;
       case 13: //ENTER
         switch (op){
            case 1:
                 derrota();  
                 break;
            case 2:
                  empresarioDificil();
                 break;    
   	    }
   }
	}else{
    switch (tecla){
       case 119:  //pra cima
        if (op-1>=1)
             op--; 
         else
             op=2; 
             
         break;    
       case 115:  //pra baixo
         if (op+1<=2)
             op++;
             else
             op=1;
         break;
       case 13: //ENTER
         switch (op){
            case 1:
                 sucesso();  
                 break;
            case 2:
                 derrota();
                 break;               
           
    }  
  } 
} 
  } while (tecla !=27);

    
  textbackground(0);
  system("cls");
	
	
	
}
//-----------------------------------------------------------------------------    

void jogoDificil(){
	
   cont = 3;
	
   textbackground(4);
   textcolor(0);
   system("cls");
   gotoxy(41,4);  printf("-------Bem-Vindo ao Dream�s Life--------");
   gotoxy(31,14); printf("===============================================================");
   gotoxy(44,15); printf("Voc� escolheu a dificuldade dificil");
   gotoxy(42,16); printf("Para jogadores que ja tenham uma experi�ncia");
   gotoxy(45,17); printf("em raciocinio e querem um desafio");
   gotoxy(31,18); printf("===============================================================");
   
   int op=1; 
char tecla;

 do{  
   textcolor(15);
   textbackground(0);
   
   gotoxy(32,23); printf("   Voltar   ");
   gotoxy(80,23); printf(" Continuar ");

   textcolor(0);
   textbackground(15);
   
   switch (op){
   	  case 1: 
   	  	gotoxy(32,23); printf("   Voltar   ");
   	  	break;
      case 2:
         gotoxy(80,23); printf(" Continuar ");      
         break;
       
    }
    
    tecla=getch();  
    if (tecla<0)
      tecla=getch();
    
    
    switch (tecla){
       case 119:  //pra cima
        if (op-1>=1)
             op--; 
         else
             op=2; 
             
         break;    
       case 115:  //pra baixo
         if (op+1<=2)
             op++;
             else
             op=1;
         break;
       case 13: //ENTER
         switch (op){
         	case 1:
                 jogar();  
                 break;
            case 2:
                 login();  
                 break;
                               
           
    }  
  } 
 } while (tecla !=27);

    
  textbackground(0);
  system("cls");
   parada=getch();
}

//-----------------------------------------------------------------------------   

void lixeiroDificil(){

	
	 textcolor(0);
   textbackground(4);
   system("cls");
   gotoxy(30,11); printf("===================================================================");
   gotoxy(30,12); printf("Com o tempo trabalhando de pedreiro voce conseguiu subir de cargo");
   gotoxy(30,13); printf("e consequentemente virando chefe de obra, melhorando suas condicoes");
   gotoxy(30,14); printf("de vida, e vivendo bem com sua familia, mas seus pedreiros est�o");
   gotoxy(30,15); printf("roubando materias de voce, voce corrije eles e pune eles ou deixa isso quieto?");
   gotoxy(30,16); printf("===================================================================");
   
int op=1; 
char tecla;

 do{  
   textcolor(0);
   textbackground(4);
   
   gotoxy(57,19); printf("  corrija eles  ");
   gotoxy(57,20); printf("  esque�a disso  ");

   
   textcolor(0);
   textbackground(15);
   
   switch (op){
      case 1:
         gotoxy(57,19); printf("  corrija eles  ");
         break;
      	case 2:
      		 gotoxy(57,20); printf("  esque�a disso  ");
      		 break;
   
          
    }
    
    tecla=getch();  
    if (tecla<0)
      tecla=getch();
      
 
    if (cont == 3){
        switch (tecla){
       case 119:  //pra cima
        if (op-1>=1)
             op--; 
         else
             op=2; 
             
         break;    
       case 115:  //pra baixo
         if (op+1<=2)
             op++;
             else
             op=1;
         break;
       case 13: //ENTER
         switch (op){
            case 1:
                 sucesso();  
                 break;
            case 2:
                 derrota();
                 break;    
   	    }
   }
	}
	else{
    switch (tecla){
       case 119:  //pra cima
        if (op-1>=1)
             op--; 
         else
             op=2; 
             
         break;    
       case 115:  //pra baixo
         if (op+1<=2)
             op++;
             else
             op=1;
         break;
       case 13: //ENTER
         switch (op){
            case 1:
                 sucesso();  
                 break;
            case 2:
                 derrota();
                 break;               
           
    }  
   } 
  }
} while (tecla !=27);

    
  textbackground(0);
  system("cls");

	
}
//-----------------------------------------------------------------------------   

void desenvolvedorDificil(){
	textcolor(0);
   textbackground(4);
   system("cls");
   gotoxy(30,11); printf("===============================================================");
   gotoxy(30,12); printf("agora voce trabalha na matera, uma das maiores empresas da america");
   gotoxy(30,13); printf("latina, porem voce brigou com seu chefe mesmo estando certo, voce");
   gotoxy(30,14); printf("vai at� ele e pede desculpas ou deixa seu ego ser maior ?");
   gotoxy(30,15); printf("");
   gotoxy(30,16); printf("===============================================================");
   
int op=1; 
char tecla;

 do{  
   textcolor(0);
   textbackground(4);
   
   gotoxy(57,19); printf("  Pe�a desculpas  ");
   gotoxy(57,20); printf("  Deixe seu ego ser maior  ");

   
   textcolor(0);
   textbackground(15);
   
   switch (op){
      case 1:
         gotoxy(57,19); printf("  Pe�a desculpas  ");
         break;
      	case 2:
      		 gotoxy(57,20); printf("  Deixe seu ego ser maior  ");
      		 break;
   
          
    }
    
    tecla=getch();  
    if (tecla<0)
      tecla=getch();
      
 
    if (cont == 3){
        switch (tecla){
       case 119:  //pra cima
        if (op-1>=1)
             op--; 
         else
             op=2; 
             
         break;    
       case 115:  //pra baixo
         if (op+1<=2)
             op++;
             else
             op=1;
         break;
       case 13: //ENTER
         switch (op){
            case 1:
                 sucesso();  
                 break;
            case 2:
                 derrota();
                 break;    
   	    }
   }
	}
	else{
    switch (tecla){
       case 119:  //pra cima
        if (op-1>=1)
             op--; 
         else
             op=2; 
             
         break;    
       case 115:  //pra baixo
         if (op+1<=2)
             op++;
             else
             op=1;
         break;
       case 13: //ENTER
         switch (op){
            case 1:
                 sucesso();  
                 break;
            case 2:
                 derrota();
                 break;               
           
    }  
   } 
  }
} while (tecla !=27);

    
  textbackground(0);
  system("cls");

	
}

//-----------------------------------------------------------------------------   

void empresarioDificil(){

	
		textcolor(0);
   textbackground(4);
   system("cls");
   gotoxy(30,11); printf("================================================================");
   gotoxy(30,12); printf("Voce abriu outra franquia, agora est� desesperado cuidando de duas");
   gotoxy(30,13); printf("franquias, nao sabe o que fazer, voce est� ficando louco, � muita ");
   gotoxy(30,14); printf("coisa para voce fazer sozinho, logo acha uma pessoa que deseja ser");
   gotoxy(30,15); printf("seu s�cio comprando 35 porcento da sua empresa, deseja vender e ter");
   gotoxy(30,16); printf("um s�cio, ou cuidar de tudo sozinho ?");
   gotoxy(30,17); printf("Voc� aceita a proposta %s?",nome);
   gotoxy(30,18); printf("================================================================");
   
int op=1; 
char tecla;

 do{  
   textcolor(0);
   textbackground(4);
   
   gotoxy(53,22); printf("  Ter um s�cio ");
   gotoxy(53,23); printf("  Continuar sozinho  ");

   
   textcolor(0);
   textbackground(15);
   
   switch (op){
      case 1:
         gotoxy(53,22); printf("  Ter um s�cio ");
         break;
      	case 2:
      		 gotoxy(53,23); printf("  Continuar sozinho  ");
      		 break;
   
          
    }
    
    tecla=getch();  
    if (tecla<0)
      tecla=getch();
       
    
  
    if (cont == 3){
        switch (tecla){
       case 119:  //pra cima
        if (op-1>=1)
             op--; 
         else
             op=2; 
             
         break;    
       case 115:  //pra baixo
         if (op+1<=2)
             op++;
             else
             op=1;
         break;
       case 13: //ENTER
         switch (op){
            case 1:
                 sucesso();  
                 break;
            case 2:
                  derrota();
                 break;    
   	    }
   }
	}else{
    switch (tecla){
       case 119:  //pra cima
        if (op-1>=1)
             op--; 
         else
             op=2; 
             
         break;    
       case 115:  //pra baixo
         if (op+1<=2)
             op++;
             else
             op=1;
         break;
       case 13: //ENTER
         switch (op){
            case 1:
                 sucesso();  
                 break;
            case 2:
                 derrota();
                 break;               
           
    }  
  } 
} 
  } while (tecla !=27);

    
  textbackground(0);
  system("cls");
	
	
	
	
	
	
	
	
}
//-----------------------------------------------------------------------------   
