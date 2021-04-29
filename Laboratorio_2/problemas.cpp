#include "PROBLEMAS.h"
#include "auxiliar.h"


        //Probelma #2


void problema2(){

    srand(time(NULL)) ;
    int contador = 0 ;
    char arreglo_random[200], letra_mayus[]="QWERTYUIOPASDFGHJKLZXCVBNM" ;   //Tamaño del arreglo:26



    for( int i = 0 ; i < 200 ; i++ ){               //Ciclo que recorre y llena el arreglo de caracteres random

        char l_mayus = letra_mayus[ rand() % 26 ] ;     //Letra mayuscula aleatoria

        arreglo_random[i] = l_mayus ;

    }


    cout << endl << " Arreglo Aleatorio:" << endl ;

    for( int c = 0 ; c < 200 ; c++ ){           //Ciclo que imprime el arreglo aleatorio creado

        cout << arreglo_random[c] ;

    }

    cout << endl << endl ;

    for( int i = 0 ; i < 26 ; i++ ){          //Ciclo que recorrera el arreglo aleatorio y busca los caracteres repetidos

        char letra = letra_mayus[i] ;

        for( int a = 0 ; a < 200 ; a++ ){       //El primero obtiene el caracter y el segundo lo compara en el A.random

            char letra2 = arreglo_random[a] ;

            if( letra == letra2 ){

                contador++ ;

            }

        }

        cout << " La letra " << letra << " se repite: " << contador << " veces." << endl ;

        contador = 0 ;

    }

    cout << endl ;

}





        //Problema #3


bool problema3(char *c1, char*c2){

    int long1, long2  ;

    bool retorno = false ;

    long1 = longitud( c1 ) ;
    long2 = longitud( c2 ) ;

    if( long1 == long2 ){

       retorno = comparacion( long1 , c1 , c2 ) ;

    }
    else{

        retorno = false ;
    }

    return retorno ;

}




        //Problema #4


long long int problema4(char *c){

    long long int n_entero = 0 , conversion ;

    for( int i = 0 ; *( c + i ) != '\0' ; i++ ){

        conversion = int( *( c + i ) ) - 48 ;           //restamos 48 para obtener el numero de char a int

        n_entero = ( n_entero*10 ) + conversion ;       //Con esta linea obtenemos lo ingresado

    }

    return n_entero ;

}




        //Problema #5


void problema5(int num, char *c){

    int n_dig, parametro, cociente, modulo, r_div ;

    char caracter ;

    cociente = num ;

    n_dig = obtener_digitos( num ) ;            //Obtenemos el numero de digitos del numero

    parametro = n_dig - 1 ;

    for( int i = 1 ; i <= n_dig ; i++ ){

        modulo = cociente%10 ;
                                                //Obtenemos el ultimo digito del numero
        r_div = cociente/10 ;

        caracter = convertira_caracter( modulo ) ;      //Funcion que convierte el numero de entero a caracter

        *( c + parametro ) = caracter ;         //Almacenamos en la direccion de memoria el caracter

        cociente = r_div ;                      //Funciona desde #digitos y termina en la posicion 0

        parametro-- ;
    }

}




        //Problema #6


char * problema6(char *c){

    static char copia[50] ;        //Usamos static para que no se elimine el arreglo luego de que la funcion sea llamada

    char c_mayus ;

    for( int i = 0 ; *( c + i ) != '\0' ; i++ ){

        if( *( c + i ) >= 97 && *( c + i ) <= 122 ){                //Rango de las minusculas

            c_mayus = *( c + i ) - 32 ;             //Transformacion de minus a mayus

            *( copia + i ) = c_mayus ;

        }
        else{

            *( copia + i ) = *( c + i ) ;

        }

    }


    return copia  ;

}




        //Problema #7


void problema7(char *c){

    eliminacion_impresion( c ) ;

}




        //Problema #8


void problema8(char *c1, char *c2){


    impresion_original( c1 );

    impresion_texto( c1, c2 );      //Funciones que imprimen los 3 arreglos


}



        //Problema #9

long long int problema9(char *c, long long int n){

    int l, n_veces ;

    long long int suma_total = 0 ;

    l = longitud( c ) - 1 ;         //Sacamos la longitud al arreglo

    if( l % n == 0 ){

        n_veces = l/n ;     //Con esta linea, miramos en cuantas partes se dividira el arreglo entero

        suma_total = dividir_sumar( n_veces, n , c );


    }
    else{                   //Si el arreglo nos divisible por n

        int ceros = 0 ;

        ceros = l ;

        while( ceros%n != 0 ){          //Numero de ceros que se deben agregar al arreglo

            ceros++ ;

        }

        n_veces = ceros/n ;

        char nuevo_ar[ceros] ;

        char *p_ceros ;         //Guarda la direccion de nuevo_ar modificado por la funcion

        p_ceros = ceros_func( c, nuevo_ar, ceros, l );

        suma_total = dividir_sumar( n_veces, n, p_ceros );

    }

    return  suma_total ;

}




        //Problema #10



long long int problema10(char *c){

    long long int suma = 0 ;

    int n, valor_letra_actual, valor_letra_siguiente, b ;

    char actual, siguiente ;

    n = longitud( c ) - 1 ;     //longitud del arreglo

    if( n > 1 ){

        b = n - 1 ;

        for( int i = 0 ; i < b ; i++ ){

            actual = c[i] ;               //Valores de la cadena

            siguiente = c[i+1] ;

            valor_letra_actual = valor_letra( actual );

            valor_letra_siguiente = valor_letra( siguiente );

            if( valor_letra_actual == 69 || valor_letra_siguiente == 69 ){    //Se verifica que los caracteres de la cadena
                                                                                        //Sean validos todos
                cout << endl << " INGRESE UNA CADENA DE CARACTERES VALIDA..." << endl ;

                suma = 0 ;

                break;

            }
            else{

                if( valor_letra_actual >= valor_letra_siguiente ){

                    suma = suma + valor_letra_actual ;
                                                        //Condiciones que miran si el valor de la letra se debe sumar o restar
                }
                else if( valor_letra_actual < valor_letra_siguiente ){

                    suma = suma - valor_letra_actual ;

                }

                if( i == b-1 ){

                    suma = suma + valor_letra_siguiente ;       //Sumamos la ultima letra ya que el ciclo no llega hasta ella

                }


            }

        }

    }
    else if( n == 1 ){

        actual = c[0] ;

        valor_letra_actual = valor_letra( actual ) ;

        if( valor_letra_actual != 69 ){         //Verificamos si la letra ingresada es un caracter valido

            suma = valor_letra_actual ;
        }
        else{

            cout << endl << " INGRESE UNA CADENA DE CARACTERES VALIDA..." << endl ;
        }

    }
    else{

        cout << endl << " INGRESE UNA CADENA DE CARACTERES VALIDA..." << endl ;

    }

    return suma ;

}




        //Problema #11


void problema11(char c, char *c2){

    char cine[15][20] ;

    int numero = 1, pf,pc ;

    char letra = 65 ;

    //Rellenamos

    for(int f = 0 ;f<15;f++ ){

        for(int c = 0;c<20 ;c++ ){

            cine[f][c] = '-';

        }
    }

    //OBTENEMOS LOS VALORES INGRESADOS

    int n, v_fila, v_colum, cont=0, v_ing, c_s ;

    bool condicion = true ;

    char fila ;

    n = longitud( c2 ) - 1 ;

    fila = c2[0];   //Letra

    while( condicion == true ){



            switch( c ){

                case 'R' :

                    v_fila = val_fil( fila );

                    if(cont ==0){

                        v_colum = val_colum( c2, n);
                    }
                    else {

                        v_colum = v_ing - 1 ;
                    }

                    cine[v_fila][v_colum] = '+' ;

                break;

                case 'C' :

                v_fila = val_fil( fila );

                if(cont ==0){

                    v_colum = val_colum( c2, n);
                }
                else {

                    v_colum = v_ing - 1 ;
                }

                cine[v_fila][v_colum] = '-' ;

                break;





           }


        //Imprimimos nuevamente

            letra = 65 ;
            numero = 1;

            for( int a = 0;a<16;a++ ){

                for( int b = 0 ;b<21;b++ ){

                    pf = a -1;
                    pc = b-1 ;

                    if( a == 0 ){

                        if( b == 0 ){

                            cout << "   " ;
                        }
                        else if( b < 10 ){
                            cout << " " << numero << "   " ;        //Numeros en las columnas
                            numero = numero + 1;
                        }
                        else {
                            cout << " " << numero << "  " ;
                            numero = numero + 1;
                        }

                    }
                    else if( b == 0 ){

                        cout << letra << "  " ;
                        letra = letra + 1 ;
                    }
                    else {

                        cout << "[" << cine[pf][pc] << "]" << "  " ;


                    }



                }

                cout << endl ;


            }


            cout << endl << endl << " > Que desea hacer ahora?" << endl ;
            cout << endl << " Continuar: 0   ||    Salir: 1" << endl ;
            cout << endl << " RESPUETSA: " ;
            cin >> c_s ;

            if( c_s == 0 ){

               cout << endl << " Ingrese [R] si desea reservar o [C] si desea cancela..." << endl ;
               cin >> c ;
               cout << endl << endl << " Ahora ingrese el asiento [letra] y luego [numero] ";
               cin >> fila >> v_ing ;
               cout << endl ;
               cont++;


            }
            else{

                condicion = false ;
            }

    }

}



        //Problema #12


bool problema12(int *mat, int elementos){

    imprimir_cuadro_magico(mat,elementos);      //Imprimimos el cuadrado mágico

    bool magico = false ;

    //Ahora comfirmamos si es realmente magico

    //Primero verificamos que no hayan numeros repetidos

    magico = repeticion_m(mat,elementos);

    if( magico == 1 ){

        //Re-organizamos en el arreglo en una matriz como tal con ayuda de la memoria dinamica

        int **m ;

        int e = sqrt(elementos);

        int *fil, *col, diag[2] = {0,0} ;

        fil = new int[e] ;

        col = new int[e] ;

        for( int k = 0 ; k < e ; k++ ){     //Inicializamos en 0 todo elarreglo

            fil[k] = 0 ;

            col[k] = 0 ;

        }



        m = matriz( mat, elementos);

        for( int f = 0 ; f < e ; f++ ){

            for( int c = 0 ; c < e ; c++ ){

                fil[f] = fil[f] + m[f][c] ;

                col[c] = col[c] + m[f][c] ;

                if( f == c ){

                   diag[0] = diag[0] + m[f][c] ;
                }

                if( f == (e-1)-c ){

                    diag[1] = diag[1] + m[f][c] ;

                }


            }


        }


        //Ahora verificamos si la sumas de todas las columnas, filas y diagonales den la misma constante


        for( int v = 1 ; v < e ; v++ ){

            if( (fil[v] == fil[v-1]) && (col[v] == col[v-1]) ){

                magico = true ;

            }
            else{

                magico = false ;
            }

        }

        if( diag[0] == diag[1] ){

            magico = true ;
        }
        else{

            magico = false ;

        }


        if( (fil[0] == diag[0]) && (fil[0] == col[0]) && (col[0] == diag[0]) ){

           magico = true ;
        }
        else{

           magico = false ;
        }



    }
    else if( magico == 0 ){

        cout << " La Matriz ingresada NO es un cuadrado mágico..." << endl ;

    }

    return magico ;

}





        //Problema #13



int problema13(int *mat){

    int imagen[6][8], estrellas = 0 ;

    float logica ;

    //Rellenamos la matriz imagen

    for( int f = 0, i = 0 ; f < 6 ; f++ ){

        for( int c = 0 ; c < 8 ; c++, i++ ){


            imagen[f][c] = *(mat + i) ;

        }

    }


    //Recorremos la matriz para verificar el numero de estrellas

    for( int f = 1 ; f < 5 ; f++ ){    //Ignoramos los bordes al recorrer la matriz

        for( int c = 1 ; c < 7 ; c++ ){


            logica = ( imagen[f][c] + imagen[f][c-1] + imagen[f][c+1] + imagen[f-1][c] + imagen[f+1][c] )/5.0 ;

            if( logica > 6 ){

               estrellas++ ;

            }

        }

    }

    return estrellas ;

}






        //Problema #14


void problema14(){

    int matriz[5][5], num = 1 ;

    for( int f = 0 ; f < 5 ; f++ ){     //Rellenamos la matriz del 1 al 25

        for( int c = 0 ; c < 5 ; c++ ){

            matriz[f][c] = num ;

            num++ ;

        }

    }

    int *m_original ;

    m_original = &matriz[0][0] ;

    //AHORA IMPRIMIMOS LA MATRIZ ORIGINAL

    cout << '\t' << " Matriz Original" << endl << endl ;

    int cont = 0 ;

    for( int f = 0 ; f < 5 ; f++ ){

        for(int c = 0 ; c < 5 ; c++, cont++ ){


            if( cont < 9 ){

                cout << "[" << matriz[f][c] << " ]" << '\t' ;

            }
            else{

                cout << "[" << matriz[f][c] << "]" << '\t' ;
            }

        }

        cout << endl ;

    }


    //AHORA GENERAMOS E IMPRIMIMOS LA MATRIZ ROTADA 90°

    m_rotada_90( m_original );

    //AHORA GENERAMOS E IMPRIMIMOS LA MATRIZ ROTADA 180°

    m_rotada_180( m_original );

    //AHORA GENERAMOS E IMPRIMIMOS LA MATRIZ ROTADA 270°

    m_rotada_270( m_original );




}



        //Problema #15


void problema15(int *dato1, int *dato2, int *cruce){

    //Usamos la siguiente funcion para verificar si efectivamnte, los rectangulos se cruzan

    bool cond ;

    cond = verif_mat(dato1, dato2);     //true: si hay cruce, false: en el caso contario

    if( cond ){


        coordenadas_cruce(dato1,dato2,cruce);       //Funcion que modifica el arreglo cruce e

                                            //Introduce en el los datos correspondientes al nuevo rectangulo
    }
    else{

        cout << " NO hay cruce entre ambos arreglos... " << endl ;

        cruce[0] = 0 ;
        cruce[1] = 0 ;
        cruce[2] = 0 ;
        cruce[3] = 0 ;

    }


}



        //Problema #16



int problema16(int n){

    int caminos = 0 ;

    caminos = recursiva( 0, 0, n, caminos );

    return caminos ;

}





        //Problema #17


int problema17(int num){

    int suma = 0, a, b, pos = 0 ;

    int *amigables = new int[num] ;

    for( int f = 0 ; f < num ; f++ ){

       amigables[f] = 0 ;
    }


    if( num > 0 ){

        for( int i = 1 ; i < num ; i++ ){

            a = suma_divisores( i );

            if( a < num ){

                b = suma_divisores( a );

                if( b == i && i != a ){       //los numeros son amigables

                    amigables[ pos ] = a ;
                    amigables[ pos+1 ] = b ;

                    pos++ ;

                }

            }

        }

        suma = suma_sin_repetir(amigables,num);

    }
    else{

       cout << " Ingrese un numero valido..." << endl ;

    }

    return suma ;

}





        //Problema #18


void problema18(char *p, int n){

    char *m ;

    if( n >= 1 && n <= (factorial(10)) ){

       m = permutaciones( n-1, 10 );

       for( int i = 0 ; m[i] != '\0' ; i++ ){

            p[i] = m[i] ;
       }

       p[10] = '\0' ;

    }
    else{

        cout << " El numero de permutacion NO es valido..." << endl ;
    }

}
