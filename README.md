# Juego Set
### Proyecto Introducción a la Programación curso 2021/2022 UEx
__**El proyecto obtuvo la calificación máxima en la convocatoria de Enero**__

Set es un juego de mesa para uno o más jugadores. Se pueden encontrar muchas versiones distintas para jugar en un
navegador o en el móvil.
Por ejemplo, https://smart-games.org/en/set/submit_set.
Para teléfonos Android se puede encontrar el juego Find a set! en Google Play.
El objetivo del juego es identificar conjuntos (set) de 3 cartas a partir de las cartas que se van mostrando.
Cada carta tiene 4 características distintas:
- Número: en cada carta hay 1, 2 o 3 elementos, todos ellos iguales.
- Forma: los elementos de cada carta pueden ser elipses, rombos u ondas. Todos los elementos de cada carta tienen la
misma forma.
- Color: los elementos de cada carta pueden ser azules, verdes o rojos. Todos los elementos de cada carta tienen el
mismo color.
- Relleno: los elementos de cada carta pueden estar vacíos, rayados o rellenos. Todos los elementos de cada carta tienen
el mismo relleno.

Se parte de una baraja de 81 cartas distintas (las 81 combinaciones diferentes que se pueden formar con las 3 posibilidades
de cada una de las 4 características: 34 = 81). Inicialmente, en el tablero se suelen mostrar 12 cartas.

![image](https://user-images.githubusercontent.com/99427949/207420520-40accaa2-10f2-46a0-8397-1b8718794888.png)



Con las teclas de los cursores (←↑↓→) podremos ir desplazándonos por las cartas del tablero. Para seleccionar una carta
deberemos pulsar la tecla Enter. Una vez seleccionadas 3 cartas, si forman un conjunto (set), esas cartas desaparecerán,
se sustituirán por otras de la baraja y se incrementará el número de puntos conseguidos.
En la versión original, el juego termina cuando no se puede formar ningún set.
Un conjunto o set estará formado por 3 cartas cuyas cuatro características sean iguales o distintas en todas ellas.
Por ejemplo, en la imagen siguiente, las tres cartas seleccionadas (enmarcadas en rojo) forman un set ya que todas ellas
tienen distinto número, distinta forma, distinto color y distinto relleno.

![image](https://user-images.githubusercontent.com/99427949/207420604-383d131b-fc01-40ec-a7f5-2ce0ede7755a.png)



La imagen siguiente muestra otro ejemplo de 3 cartas seleccionadas que también forman un set ya que todas tienen el
mismo color y todas tienen distinto número, forma y relleno.

![image](https://user-images.githubusercontent.com/99427949/207420971-c7035b25-81e7-4281-ae03-99ae1d8200c9.png)



Cada vez que se encuentra un set, el programa eliminará las 3 cartas seleccionadas en la jugada anterior y, en su lugar,
mostrará 3 cartas nuevas. Las restantes cartas permanecerán en su sitio. La siguiente imagen muestra una posible
configuración del tablero tras seleccionarse las 3 cartas de la imagen anterior.

![image](https://user-images.githubusercontent.com/99427949/207421020-f2c50fe3-5777-4666-9320-6b32eaa5e3e1.png)



A continuación, se muestran algunos ejemplos más de tríos de cartas que forman set y tríos de cartas que no.

![image](https://user-images.githubusercontent.com/99427949/207421284-8bf4a991-2194-4809-80db-81373d54aca2.png)


