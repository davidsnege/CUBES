
![Screenshot](https://github.com/davidsnege/CUBES/blob/main/DesignMKT/img/negro_L.png?raw=true)

Comunicaciones Unificadas Basadas en Espacio

## Que se propone

La propuesta es crear un modelo de cubeSat de tamaño 1U basado en su primer versión en arduino y modulos de comunicación por rádio, sobre todo L.O.R.A que es una tecnologia que me ha llamado la atención.

La pretensión es llevar a cabo este proyecto sin plazos, mantener el repositorio organizado y de una forma que sea de fácil interpretación por otros que lo necesiten en un futuro.

La licencia inicial es "No comercial y no distribuible o modificable" por el simples hecho de que no puedo solo controlar y hacerme responsable por monitorear y ayudar en desarollo de otras personas.

El objectivo final es que tengamos un nanosatelite funcional con control de estabilización, orientación de la camara hacia el planeta, envio de datos de telemetria, envio de imagem actual a cada 5 minutos en baja resolución para pruebas, gestión de energia y cargado de baterias.

La orbita aun no esta definida, por lo que puede ser estacionaria o polar, se debe pensar en las dos opciones y esto no debe de ser un problema, el nanosatelite debe ser capaz de operar en las dos situaciones.

- En todo texto vamos nos referir a nuestros satelites como (nanosatelites) o (cubesats) aunque se pueda trabajar con otras categorias que no sea la (1U) la nomenclatura utilizada va ser (nanosatelite) para dejar más claro y fluido el texto.

## Uso del repositorio git

1. Ramas permitidas para desarollo
- desarollo (Rama principal de inicio de los proyectos se debe especificar una rama abajo para el trabajo)
- - conceptual (En fase de desarollo primario y conceptual, no incluido aun en el proyecto)
- - feature (Nuevo feature que ha salido bien en la rama anterior)
- - hotfix (Correción de errores o bugs que se necesita hacer de algun feature ya existente)
- pre (Rama de testeo de primeros prototipos)
- - feature (Nuevo feature que ha salido bien en la rama anterior)
- - hotfix (Correción de errores o bugs que se necesita hacer de algun feature ya existente)
- pro (Rama de todo que ya esta en su ultimo testeo de pruebas)
- - feature (Nuevo feature que ha salido bien en la rama anterior)
- - hotfix (Correción de errores o bugs que se necesita hacer de algun feature ya existente)
- main (Rama oficial donde solo debe tener los desarollos concluidos y funcionales como su documentación, no se aceptara en esta rama nada sin documentar o codigo sin comentarios, si comentamos codigo)

## Versionamento de software

Se debe utilizar la seguinte estructura.

| C | D | M | A | S | T |
| - | - | - | - | - | - |
| Control | Día   | Mes | Año | Semana | Tipo |
| 0001 | 01 | 01 | 2023 | 01 | b |

El nombre de esta version se traduce : 0010101202301b

- Los tipos son: b (beta) a (alpha) r (release) 

1. Las versiones b (beta) son reservadas a versiones casi estables para pruebas de features aun inestables.

2. Las versiones a (alpha) son reservadas a versiones no estables y que no van a ser corregidas lanzadas para corregir algun hotfix detectado en versiones anteriores.

3. Las versiones r (release) son las versiones estables finales de cada ciclo.

## Softwares a utilizar

```` Preferiblemente vamos a utilizar softwares gratuitos o libres, como sistema operativo se recomenda el uso de Ubuntu o derivados de Linux/Debian, si no es posible utilizar softwares y sistemas gratuitos utilizar lo que se pueda en su momento siempre que se tenga la licencia de uso.````

1. Para crear codigo y subir codigo
- Para hacer upload siempre usamos la IDE oficial de Arduino.
- Se puede hacer uso de VScode para componer los codigos si es mas comodo.

2. Para prototipos de construcción de PCBs
- Primeramente Fritizing aunque sea de pago y por si necesário LibrePCB.
- En un ultimo caso podemos utilizar TinkerCad.

3. Github Desktop para gestión del repositório o el terminal.

4. Radio y Comunicaciones
- GQRX para depuración o debug de frequencias enviadas.
- FLDIGI para decodificación de datos por radio o WEFAX.
- CubicSDR si necesário monitorear mas de una frequencia a la vez.
- RTL_433 si por acaso necesitamos mirar si nuestro L.O.R.A esta abierto.

5. Diseños Marketing o otros
- Usar inkscape para vectores.
- Usar Gimp para imagenes.
- Usar Libre Office para documentaciones plantillas o lo que se necesite.
## Inversiones, inversores y capital

En un primer momento no esperamos utilizar modelos de Crowdfunding o otros modelos de arrecadación de recursos por el simples hecho de que planteamos en realidad que este proyecto sea profesional y cuente con inversores en modo startup o inversiones de capital para la formación de una empresa (CUBE) especializada en la creación de este tipo de nanosatelites y en un futuro desarollo de cohetes de pequeño tamaño para la inserción en baja orbita de hasta 200km de satelites tamaño 1U.

Sabemos que salir de la etapa de prototipo hasta la empresa es un salto enorme, y por eso no tenemos pretensiones de tan pronto tener inversores, eso conllevaria plazos, presiones, maquetación a la marcha y lo que necesitamos antes de nada es tener un proyecto estable y viable para poder ofrecer al mercado alguna solución que sea factible y utilizable por futuros clientes.

Los costes de mantener un despacho con los equipos, personal, impuestos y cuentas en marcha no esta aun en nuestro alcance, por lo tanto en un futuro si que necesitamos de inversores, serios, comprometidos con este proyecto y personal calificado para los desarollos, es importante que toda tecnologia desarollada en este proyecto permanezca de manera confidencial y lejos de personas ajenas, por este motivo el repositorio debe permanecer privado y toda manufactura de construcción debe ser mantenida y desarollada internamente.

El precio para venta del desarollo a un cliente podria llegar a €200 mil euros, en consideración a cambios y especificaciones, esto es distinto del precio de lanzamiento del satelite que puede tener disparidades conforme se elije la empresa a que vá poner el satelite en orbita y el tipo de orbita, en SpaceX se puede llegar a lanzar (en este momento) un nanosatelite de tipo 1U por hasta €15 mil euros.

La vida util de un nanosatelite hoy es estimada en 5 hasta 15 años y eso depende de la tecnologia empleada y las protecciones de redundancia atribuidas al proyecto, este tiempo util y su bajo precio hacen aceptables los lanzamientos programados a cada 5 años con los beneficios que se puede obtener.