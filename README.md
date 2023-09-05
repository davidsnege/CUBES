
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
...