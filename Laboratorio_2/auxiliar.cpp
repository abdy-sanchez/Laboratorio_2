#include "auxiliar.h"
#include "PROBLEMAS.h"

   //FUNCIONES EXTRA

int longitud( char *arreglo ){

    int i = 0 ;

    for(  ; *( arreglo + i ) != '\0' ; i++ ){

        //Ciclo que se repite las veces que se cumple la condicion
    }

    return i+1;

}



bool comparacion( int longi, char *ar1, char *ar2 ){

    int cont_comparacion = 0 ;

    bool r_comp ;

    for( int i = 0 ; i < longi ; i++ ){

        if( *( ar1 + i ) == *( ar2 + i ) ){

           cont_comparacion++ ;
        }

    }

    if( cont_comparacion == longi ){

        r_comp = true ;
    }
    else{

        r_comp = false ;
    }

    return r_comp ;

}



int obtener_digitos( int num ){

    int r_div, num_digitos = 0 ;

    r_div = num ;

    do{

        r_div = r_div/10 ;

        num_digitos++ ;

    }
    while( r_div > 0 ) ;

    return num_digitos ;

}



char convertira_caracter( int n_ent ){

    char caracter = 48 ;

    caracter = caracter + n_ent ;

    return  caracter ;

}



void imprimir_arreglos( char *a1 ){         //Funcion complementaria del problema 6

    char *a_copia ;

    int t_original = 0 ;

    a_copia = problema6( a1 ) ;

    cout << endl << " Arreglo Original: " ;

    for( int i = 0 ; *( a1 + i ) != '\0' ; i++ ){       //Imprime el arreglo original

        cout << *( a1 + i ) ;

        t_original++ ;
    }

    cout << endl ;

    cout << endl << " Arreglo en Mayusculas: " ;

    for( int e = 0 ; e < t_original ; e++ ){        //Imprime el arreglo con mayusculas

        cout << *( a_copia + e ) ;

    }

    cout << endl << endl ;

}



char *rellenar( char *ar, int n ){

    for( int i = 0 ; i < n ; i++ ){

        *( ar + i ) = ' ' ;

    }

    return ar ;

}


void eliminacion_impresion( char *ar ){

    int coincidencia1 = 0, coincidencia2 = 0, n, pos = 0 ;

    n = longitud( ar ) ;

    char sin_repetir[n] ;

    for( int i = 0 ; i < n ; i++ ){     //Rellenamos el arreglo con caracteres espacio

        *( sin_repetir + i ) = ' ' ;

    }

    for( int i = 0 ; *( ar + i ) != '\0' ; i++ ){      //Ciclo que se mueve un caracter a la vez



        for( int e = 0 ; *( ar + e ) != '\0' ; e++ ){   //Ciclo que recorre todo el arreglo

            if( *( ar + i ) == *( ar + e ) ){       //Revisa si hay coincidencia. c1 ==1 si la letra no se repite mas de 1 vez

                coincidencia1++ ;
            }

        }

        if( coincidencia1 == 1 ){               //Si no se repite, lo guarda direcamente

            *( sin_repetir + pos ) = *( ar + i ) ;

            pos = pos + 1 ;     //Actualizamos la posicion


        }
        else if( coincidencia1 > 1 ){       //Si se repite, realiza este nuevo cilo
                                            //Y mira otra vez si el caracter esta en los que no se repiten

            for( int a = 0 ; a < n ; a++ ){

                if( *( ar + i ) == sin_repetir[a] ){

                    coincidencia2++ ;

                }

            }

            if( coincidencia2 == 0 ){       //Si la letra se repite PERO no esta en el arreglo de sin repetecion, lo guarda

                *( sin_repetir + pos ) = *( ar + i ) ;

                pos = pos + 1 ;

            }

        }

        coincidencia1 = 0 ;
        coincidencia2 = 0 ;

    }

    cout << endl << " Arreglo Original: " ;

    for( int i = 0 ; *( ar + i ) != '\0' ; i++ ){

        cout << *( ar + i ) ;
    }

    cout << endl << endl << " Sin repetidos: " ;

    for( int t = 0 ; t < n ; t++ ){


        cout << sin_repetir[t] ;
    }

    cout << endl << endl ;


}


void impresion_numeros( char *og ){

    int pos = 0, ad = 1 ,n;

    n = longitud(og);

    char num[n] ;

    rellenar( num , n);

    num[n-1] = '\0' ;

    bool cond1,cond2;

    for( int h = 0 ; *( og + h ) != '\0' ; h++ ){

        cond1 = *( og + h ) >= 48 ;

        cond2 = *( og + h ) <= 57;

        if( cond1 == true && cond2 == true ){

            *( num + pos ) = *( og + h ) ;

            num[ad] = '\0' ;

            pos++;
            ad++;

        }

    }
    cout << endl ;
    cout << " Numeros: " ;

    for( int w = 0 ; *( num + w ) != '\0' ; w++ ){

        cout << *( num + w ) ;
    }


}

void impresion_original( char *ar ){

    cout << endl << " Arreglo Original: " ;

    for( int i = 0 ; *( ar + i ) != '\0' ; i++ ){

        cout << *( ar + i ) ;

    }

    impresion_numeros( ar);

}

void impresion_texto( char *ar, char *ar_2 ){

    bool cond1, cond2 ;

    int posicion = 0 ;

    for( int y = 0; *( ar + y ) != '\0' ; y++ ){

        cond1 = *( ar + y ) >= 65 && *( ar + y ) <= 90 ;        //letras mayusculas
        cond2 = *( ar + y ) >= 97 && *( ar + y ) <= 122 ;           //letras minus

        if( cond1 == true || cond2 == true ){

           *( ar_2 + posicion ) = *( ar + y ) ;

           *( ar_2 + ( posicion + 1 ) ) = '\0';

            posicion++;

        }

    }

    cout << endl << " Texto: " ;

    for(int z = 0 ; *( ar_2 + z ) != '\0' ; z++ ){

        cout << *( ar_2 + z ) ;
    }

    cout << endl ;

}


long int dividir_sumar( int veces , long long int n, char *ar ){

    int a = 0, b, conversion ;

    long int suma = 0, numero = 0 ;

    for( int i = 1 ; i <= veces ; i++ ){        //Ciclo uqe se repite en el numero en que esta divido todo el arreglo

        b = i*n ;           // Cantidad de caracteres que se toman cada repeticion

        for(  ; a < b ; a++ ){              //Ciclo que va de n(numero ingresado) en n hasta el final de arreglo

            conversion = int( *( ar + a ) ) - 48 ;
                                                    //Convertimos el caracter a numero
            numero = ( numero*10 ) + conversion ;

        }

        suma = suma + numero ;

        a = b ;

        numero = 0;

    }

    return  suma ;          //Se devulve la suma de todo el arreglo dividido n veces

}


char *ceros_func( char *ar, char *n_ar , int ceros, int l ){

    int agregados, u = 0 ;

    agregados = ceros - l ;         //Funcion que rellena de ceros la cadena original para que pueda ser divisible por n

    for( int q = 0 ; q < ceros ; q++ ){

        if( q < agregados ){        //Condicion que verifica en donde se va a poner los ceros y hasta donde

            *( n_ar + q ) = '0' ;

        }
        else {

            *( n_ar + q ) = *( ar + u ) ;

            u++ ;

        }

    }

    return n_ar ;

}



int valor_letra( char letra ){

    int valor ;

    if( letra >= 97 && letra <= 122 ){          //Condicional que convierte de minus a mayus

        letra = letra - 32 ;
    }

    switch( letra ) {

        case 'I' :

            valor = 1 ;

        break;

        case 'V' :

            valor = 5 ;

        break;

        case 'X' :

            valor = 10 ;

        break;

        case 'L' :

            valor = 50 ;

        break;

        case 'C' :

            valor = 100 ;

        break;

        case 'D' :

            valor = 500 ;

        break;

        case 'M' :

            valor = 1000 ;

        break;

        default:

            valor = 69 ;        //Valor para identificar cuando el caracter NO es valido

        break;


    }

    return  valor ;


}



int val_colum( char *ar, int n ){

    int num = 0, conver ;

    for( int i = 1 ; i <= n-1 ; i++ ){

        conver = int( *( ar + i) ) - 48 ;

        num = (num*10)+ conver ;

    }

    num = num-1 ;

    return  num  ;            // el -1 nos da la posicion en el arreglo

}


int val_fil( char letra ){

    int valor ;

    valor = int( letra ) - 65 ;     //El resultado de la resta es la posicion en el arreglo

    return  valor ;

}



void imprimir_cuadro_magico(int *matriz, int elementos){

    int exf, tope = 0 ;       //Elementos por fila

    exf = sqrt( elementos ) ;

    cout << endl << " Cuadrado magico " << exf << "x" << exf << endl ;

    for(int i = 0 ; i < elementos ; i++ ){

        cout << *( matriz + i ) ;

        if( tope == (exf-1) ){

            cout << endl ;

            tope = 0 ;

        }
        else{

            tope++ ;

        }

    }

}



bool repeticion_m(int *mat, int elementos){

    bool requisito = true ;

    int coincidencia = 0 ;

    for(int f = 0 ; f < elementos ; f++ ){

        for(int c = 0 ; c < elementos ; c++ ){

            if( *( mat + f) == *( mat + c ) ){

                coincidencia++ ;

            }

        }

        if( coincidencia > 1 ){

            requisito = false ;

            break;

        }
        else{

            coincidencia = 0;

        }



    }

    return requisito ;

}



int recursiva(int fvert, int cvert, int n, int caminos){

    bool opciones[2] ;      // opciones[0] : mov. hacia la derecha ; opciones[1]: mov. hacia abajo

    opciones[0] = ( cvert < n ) ;

    opciones[1] = ( fvert < n ) ;

    if( fvert == n && cvert == n ){     //Si las coordenadas estan en el ultimo nodo

        caminos++ ;

    }

    if( opciones[0] ){

        caminos = recursiva( fvert, cvert+1, n, caminos );

    }

    if( opciones[1] ){

        caminos = recursiva( fvert+1, cvert, n, caminos );

    }

    return caminos ;

}



int **matriz(int *mat, int elementos){

    int n = sqrt( elementos );

    int **matriz = new int * [n] ;

    for( int i = 0 ; i < n ; i++ ){     //Rellenamos la nueva matriz con más memoria dinamica

        *(matriz + i) = new int[n] ;

    }

    //Ahora le pasamos los datos de la matriz original

    for( int f = 0 ; f < n ; f++ ){

        for( int c = 0 ; c < n ; c++ ){

            matriz[f][c] = mat[ c + f*n] ;

        }

    }

    return matriz ;

}




void m_rotada_90(int *mat){

    int **m = new int * [5] ;

    for( int i = 0 ; i < 5 ; i++ ){     //generamos la matriz que almacenara los valores rotados 90 grados

        *(m + i) = new int[5] ;

    }

    //Ahora rotamos los valores de la matriz original

    for( int c = 4, t = 0 ; c >= 0 ; c--, t++ ){      //las variables t y k son para poder movernos dentro de la matriz original

        for( int f = 0, k = 0 ; f < 5 ; f++, k++ ){

            m[f][c] = mat[ k + t*5 ] ;

        }

    }

    //IMPRIMIMOS LA MATRIZ ROTADA

    cout << endl << '\t' << " Matriz Rotada 90 grados" << endl << endl ;


    for( int f = 0 ; f < 5 ; f++ ){

        for(int c = 0 ; c < 5 ; c++ ){


            cout << "[" << m[f][c] << "]" << '\t' ;

        }

        cout << endl ;

    }

}



void m_rotada_180( int *mat ){

    int **m = new int * [5] ;

    for( int i = 0 ; i < 5 ; i++ ){     //generamos la matriz que almacenara los valores rotados 180 grados

        *(m + i) = new int[5] ;

    }

    //Ahora rotamos los valores de la matriz original

    for( int f = 4, t = 0 ; f >= 0 ; f--, t++ ){      //las variables t y k son para poder movernos dentro de la matriz original

        for( int c = 4, k = 0 ; c >= 0 ; c--, k++ ){

            m[f][c] = mat[ k + t*5 ] ;

        }

    }

    //IMPRIMIMOS LA MATRIZ ROTADA

    cout << endl << '\t' << " Matriz Rotada 180 grados" << endl << endl ;


    for( int f = 0 ; f < 5 ; f++ ){

        for(int c = 0 ; c < 5 ; c++ ){


            cout << "[" << m[f][c] << "]" << '\t' ;

        }

        cout << endl ;

    }

}




void m_rotada_270(int *mat){

    int **m = new int * [5] ;

    for( int i = 0 ; i < 5 ; i++ ){     //generamos la matriz que almacenara los valores rotados 270 grados

        *(m + i) = new int[5] ;

    }

    //Ahora rotamos los valores de la matriz original

    for( int c = 0, t = 0 ; c < 5 ; c++, t++ ){      //las variables t y k son para poder movernos dentro de la matriz original

        for( int f = 4, k = 0 ; f >= 0 ; f--, k++ ){

            m[f][c] = mat[ k + t*5 ] ;

        }

    }

    //IMPRIMIMOS LA MATRIZ ROTADA

    cout << endl << '\t' << " Matriz Rotada 270 grados" << endl << endl ;


    for( int f = 0 ; f < 5 ; f++ ){

        for(int c = 0 ; c < 5 ; c++ ){


            cout << "[" << m[f][c] << "]" << '\t' ;

        }

        cout << endl ;

    }

}




bool verif_mat(int *mA, int *mB){

    bool requisito = false ;

    int horz = 0, vert = 0 ;

    //Verificamos si hay interseccion horizontalmente

    if( ( mB[0] >= mA[0] ) && ( mB[0] <= (mA[2]+mA[0]) ) ){     //(mA[2]+mA[0]) este pedazo quiere decir
                                                                // el valor del ancho mas la cordenada desde donde inicia
        horz++ ;

    }
    else if( ( mB[0] <= mA[0] ) && ( mA[0] <= (mB[2]+mB[0]) ) ){

        horz++ ;

    }


    if( (mB[2]+mB[0]) <= (mA[2]+mA[0]) ){

       horz++ ;

    }
    else if( (mB[2]+mB[0]) >= (mA[2]+mA[0]) ){

       horz++ ;

    }


    //Verificamos si hay interseccion Verticalmente

    if( ( mB[1] >= mA[1] ) && ( mB[1] <= (mA[3]+mA[1]) ) ){

      vert++ ;

    }
    else if( ( mB[1] <= mA[1] ) && ( mA[1] <= (mB[3]+mB[1]) ) ){

       vert++ ;

    }


    if( (mB[3]+mB[1]) <= (mA[3]+mA[1]) ){

       vert++ ;

    }
    else if( (mB[3]+mB[1]) >= (mA[3]+mA[1]) ){

        vert++ ;

    }


    //Ahora segun los contadores vert y horz, si los rectangulos se cruzan

    if( vert >= 2 && horz >= 2 ){

        requisito = true ;      //cumpe por lo menos una parte del rectangulo esta adentro del otro
    }
    else{

        requisito = false ;
    }


    return requisito ;

}



void coordenadas_cruce( int *mA, int *mB, int *cruce ){

    //Empezamos con hallar las coordenadas del eje X

    if( ( mB[0] >= mA[0] ) && ( mB[0] <= (mA[2]+mA[0]) ) ){     //(mA[2]+mA[0]) este pedazo quiere decir
                                                                // el valor del ancho mas la cordenada desde donde inicia
        cruce[0] = mB[0] ;  //le llevamos a cruce la coordenada x del rectangulo B

    }
    else if( ( mB[0] <= mA[0] ) && ( mA[0] <= (mB[2]+mB[0]) ) ){

        cruce[0] = mA[0] ;      //le llevamos a cruce la coordenada x del rectangulo B

    }


    if( (mB[2]+mB[0]) <= (mA[2]+mA[0]) ){

        cruce[2] = (mB[2]+mB[0]) - cruce[0] ;      //Le llevamos a cruce

    }
    else{

        cruce[2] = (mA[2]+mA[0]) - cruce[0] ;
    }


    //Ahora hallamos las coordenadas del eje Y

    if( ( mB[1] >= mA[1] ) && ( mB[1] <= (mA[3]+mA[1]) ) ){

       cruce[1] = mB[1] ;

    }
    else if( ( mB[1] <= mA[1] ) && ( mA[1] <= (mB[3]+mB[1]) ) ){

       cruce[1] = mA[1] ;

    }


    if( (mA[3]+mA[1]) <= (mB[3]+mB[1]) ){

       cruce[3] = (mA[3]+mA[1]) - cruce[1] ;

    }
    else{


        cruce[3] = (mB[3]+mB[1]) - cruce[1] ;
    }

}





long long int factorial( int n ){


    long long int fact = 1 ;

    for(  ; n > 1 ; n-- ){

        fact = fact*n ;
    }

    return fact ;

}

void eliminar( char *p, int n ){

    for( int i = n ; p[i] != '\0' ; i++ ){

        p[i] = p[i+1] ;

    }

}


char *permutaciones( int y, int num ){

    char combina[] = "0123456789" ;

    static char  permuta[11] ;

    permuta[10] = '\0' ;

    int grupo ;

    for( ; num >= 1 ; num-- ){


        grupo = y/(factorial(num-1)) ;

        permuta[10-num] = combina[grupo] ;

        eliminar( combina, grupo );

        y = y % factorial(num-1) ;

    }

    return permuta ;

}





int suma_divisores( int n ){

    int suma = 0 ;

    for( int i = 1 ; i < n ; i++ ){

        if( n%i == 0 ){

            suma = suma + i ;

        }

    }

    return suma ;

}





int suma_sin_repetir( int *m, int num ){

    int suma_arreglo = 0, coincide = 0 ;

    for( int i = 0 ; i < num ; i++ ){

        for( int v = i+1 ; v < num ; v++ ){

            if( m[i] == m[v] ){

              coincide++ ;
            }

        }

        if( coincide == 0 ){

            suma_arreglo = suma_arreglo + m[i] ;
        }

        coincide = 0 ;
    }

    return  suma_arreglo ;
}
