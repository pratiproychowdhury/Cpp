/*
Ejercicio 1 de 2: Rotación de cadenas (30 mins)

Es necesario implementar el cuerpo de la función:
boolean isRotation (String str1, String str2)
cuya firma se describe a continuación de manera tal que la misma pueda evaluar si una cadena “str1” corresponde a una “rotación” de una cadena “str2”. En caso de que sea así deberá retornar “true”, caso opuesto “false”. 

Se entiende por rotación a una cadena cuyo caracteres son los mismos (misma cantidad también) que los de otra pero que su orden está desplazado en el sentido de las manillas del reloj.

Ej:

Dado la cadena:
str1 = abcdef

      → (leer caracteres en esta dirección)
     a
f        b
e       c
    d

son rotaciones:
str2 = bcdefa
str3 = cdefab
*/


bool isRotation (string str1, string str2) {
    
    int length = str1.size();
    
    if (str1.size() != str2.size())
        return false;
    
    for (int rotation=0; rotation<length; rotation++) {
        int pos;
        for (pos=0; pos<length; pos++) {
            if (str1[pos] != str2[(pos+rotation)%length])
                break;
        }
        if (pos == length)
            return true;
    }
    
    return false;
}
