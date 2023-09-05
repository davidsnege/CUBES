
![Screenshot](https://github.com/davidsnege/CUBES/blob/main/img/blanco.png?raw=true)

Comunicaciones Unificadas Basadas en Espacio y Satelites - ESPAÑA 

## Que se propone

A lo largo de mis proyectos he encontrado muchos retos para cumplir, pero siempre he hecho y cumplido objectivos para empresas y personas ajenas a mis pasiones o mis aficciones.

Entre mis muchas acficciones esta el espacio, la astronomia y la electrônica, y juntando eso a mi professión decidi crear este proyecto basado en otros ejemplos que he podido ver en mis pesquisas.

La propuesta es crear un modelo de cubeSat de tamaño 1U basado en su primer versión en arduino y modulos de comunicación por rádio, sobre todo L.O.R.A que es una tecnologia que me ha llamado a investigar más.

Mi pretensión es llevar a cabo este proyecto sin plazos, pero con todo que he aprendido en mi professión para mantener organizado y de una forma que sea de fácil interpretación por otros que lo necesiten en un futuro.

La licencia inicial es "No comercial y no distribuible o modificable" por el simples hecho de que no puedo solo controlar y hacerme responsable por monitorear y ayudar en desarollo de otras personas.

El objectivo final es que tengamos un nanosatelite funcional con control de estabilización, orientación de la camara hacia el planeta, envio de datos de telemetria, envio de imagem actual a cada 5 minutos en baja resolución para pruebas, gestión de energia y cargado de baterias.

La orbita un no esta definida, por lo que puede ser estacionaria o polar, se debe pensar en las dos opciones y esto no debe de ser un problema, el nanosatelite debe ser capaz de operar en las dos situaciones.

## Tecnologia para investigar y usar

Aqui nos vamos a limitar a Arduino en un primer momento, puede que en un futuro no dejemos de valorar Raspiberry o otras tecnologias como controladores, pero en principio por la experiencia y bajo coste nos vamos basar en Arduino y sus modulos.

El modulo L.O.R.A debe ser el principal a ser investigado al máximo incluso si necesário escribindo una libreria propria. 

Un modulo de GPS será util en conjunto con un modulo de brujula magnetica para posicionamiento del satelite, asi como el modulo de acelerometro de 3 ejes para una maior precisión.

La investigación y construcción de una interfaz giroscopica para orientación será valorada para ser lo menor y mas ligera posible.

En etapas más avanzadas deberemos adquirir una CNC pequeña de coste bajo para poder fabricar y testear nuestras proprias boards y hacer pruebas mejores con los componentes.

También vamos valorar la adquisición de una CNC laser para la confección de mascaras para boards.

El uso de los principios de Faraday para proteger los componentes internos de interferencias deben ser puestos a prueba.

La capacidad de dispersión de calor o frio extremos debe ser valorada para garantizar la continuidad de funcionamento de los componentes.

El uso de baterias y cargadores por medio de placas solares se debe investigar con cuidado para que no tengamos periodos sin energia y nuestro satelite quede sin contacto o mal orientado, lo que podria ocasionar un daño al sensor de la camara si este estuvier orientado hacia el Sol.

El uso de camara para envio de imagenes aun debe ser valorado, talvez no sea possible el envio de grandes cantidades de datos con L.O.R.A y esto debe ser pensado.

## Uso del Repositorio GIT

1. Ramas permitidas para desarollo
- desarollo (Rama principal de inicio de los proyectos se debe especificar una rama abajo para el trabajo)
- - conceptual (En fase de desarollo primario y conceptual, no incluido aun en el proyecto)
- - feature (Nuevo feature que ha salido bien en la rama anterior)
- - hotfix (Correción de errores o bugs que se necesita hacer de algun feature ya existente)
- pre (Rama de testeo de primeros prototipos)
- pro (Rama de todo que ya esta en su ultimo testeo de pruebas)
- main (Rama oficial donde solo debe tener los desarollos concluidos y funcionales como su documentación, no se aceptara en esta rama nada sin documentar o codigo sin comentarios, si comentamos codigo)

## Softwares a utilizar

#### Preferiblemente vamos a utilizar softwares gratuitos o libres, como sistema operativo se recomenda el uso de Ubuntu o derivados de Linux/Debian.

1. Para crear codigo y subir codigo
- Para hacer upload siempre usamos la IDE oficial de Arduino.
- Se puede hacer uso de VScode para componer los codigos si es mas comodo.

2. Para prototipos de construcción de PCBs
- Primeramente Fritizing aunque sea de pago y por si necesário LibrePCB.
- En un ultimo caso podemos utilizar TinkerCad.

3. Github Desktop para gestión del repositório o el terminal.

4. Radio y Comunicaciones
- GQRX para depuración o debug de frequencias enviadas.
- FLDIGI para decodificación de datos porm radio o WEFAX.
- CubicSDR si necesário monitorear mas de una frequencia a la vez.
- RTL_433 si por acaso necesitamos mirar si nuestro L.O.R.A esta abierto.

5. Diseños Marketing o otros
- Usar inkscape para vectores.
- Usar Gimp para imagenes.
- Usar Libre Office para documentaciones plantillas o lo que se necesite.

## Operaciones de Banda de Radio

Las operaciones de banda de radio deben respetar las limitaciones de nuestro L.O.R.A o sea que vamos a utilizar en principal la frequencia de (433MHz) para operaciones de comunicación de telemetria y si necesário de imagenes.

No vamos enviar audio o archivos de audio por radio.

Si la frequencia de 433MHz no esta permitida en el país de montagen y prototipos del nanosatelite entonces se debe plantear el uso de L.O.R.A en otras frequencias disponibles como (868 MHz) o (915 MHz) recordando que frequencias más altas tienen menor capacidad de distancias.

## Operaciones de testeo en tierra

1. Las primeras operaciones (outlab) fuera de laboratorio deben de ser hechas en espacios libres de interferencia por fuentes de radiofrequencia, como antenas de telefonia, retransmisores de radio, repetidores de ondas.

2. Los primeros testeos de altitude con uso de globo de Helio (He) deben ser hechos con los mismos asegurados por lineas de control, donde se podrá recuperar, subir y bajar de modo controlado y poder valorar medidas de campo.

3. Con seguridad de que se debe hacer un real lanzamiento de un globo de Helio (He) para comprobar sistemas y el prototipo se debe hacer cuando si tenga más de un protótipo testeado y aprobado por pelo menos 5 testeos con lo metodo anterior en dias distintos con considicones meteorologicas distintas.

- a. Se debe consultar las leyes, legislaciones, permisos y condiciones del pais.
- b. Se debe pedir permiso y obtener el concenso de las autoridades.
- c. No se debe salir de los parametros de la ley.
- d. El prototipo debe estar atado a un paracaidas suficientemente fuerte que debe estar dentro del globo, de modo que cuando este esplote por la presión de altitud el prototipo no sea destruido en la caida y no sea capaz de crear ningun daño a terceros.
- e. Ya se debe poder rastrear y localizar el prototipo con precisión minima.
- f. Se debe ser capaz de capturar y guardar toda telemetria para estudo.
- g. Un veiculo de busqueda debe estar disponivel y acompañar las posiciones del globo.


