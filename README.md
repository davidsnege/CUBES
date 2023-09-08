
![Screenshot](https://github.com/davidsnege/CUBES/blob/main/img/blanco.png?raw=true)

Comunicaciones Unificadas Basadas en Espacio y Satelites - ESPAÑA 

## Que se propone

A lo largo de mis proyectos he encontrado muchos retos para cumplir, pero siempre he hecho y cumplido objectivos para empresas y personas ajenas a mis pasiones o mis aficciones.

Entre mis muchas acficciones esta el espacio, la astronomia y la electrônica, y juntando eso a mi professión decidi crear este proyecto basado en otros ejemplos que he podido ver en mis pesquisas.

La propuesta es crear un modelo de cubeSat de tamaño 1U basado en su primer versión en arduino y modulos de comunicación por rádio, sobre todo L.O.R.A que es una tecnologia que me ha llamado la atención.

Mi pretensión es llevar a cabo este proyecto sin plazos, pero con todo que he aprendido en mi professión para mantener organizado y de una forma que sea de fácil interpretación por otros que lo necesiten en un futuro.

La licencia inicial es "No comercial y no distribuible o modificable" por el simples hecho de que no puedo solo controlar y hacerme responsable por monitorear y ayudar en desarollo de otras personas.

El objectivo final es que tengamos un nanosatelite funcional con control de estabilización, orientación de la camara hacia el planeta, envio de datos de telemetria, envio de imagem actual a cada 5 minutos en baja resolución para pruebas, gestión de energia y cargado de baterias.

La orbita aun no esta definida, por lo que puede ser estacionaria o polar, se debe pensar en las dos opciones y esto no debe de ser un problema, el nanosatelite debe ser capaz de operar en las dos situaciones.

- En todo texto vamos nos referir a nuestros satelites como (nanosatelites) o (cubesats) aunque se pueda trabajar con otras categorias que no sea la (1U) la nomenclatura utilizada va ser (nanosatelite) para dejar más claro y fluido el texto.

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

```` Preferiblemente vamos a utilizar softwares gratuitos o libres, como sistema operativo se recomenda el uso de Ubuntu o derivados de Linux/Debian, si no es posible utilizar softwares y sistemas gratuitos utilizar lo que se pueda en su momento siempre que se tenga la licenciad e uso.````

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

## Operaciones de banda de radio

Las operaciones de banda de radio deben respetar las limitaciones de nuestro L.O.R.A o sea que vamos a utilizar en principal la frequencia de (433MHz) para operaciones de comunicación de telemetria y si necesário de imagenes.

No vamos enviar audio o archivos de audio por radio.

Si la frequencia de (433MHz) no esta permitida en el país de montagen y prototipos del nanosatelite entonces se debe plantear el uso de L.O.R.A en otras frequencias disponibles como (868 MHz) o (915 MHz) recordando que frequencias más altas tienen menor capacidad de distancias.

- - Aun que no este permitido el uso en tierra por la frequencia de (433MHz) en operaciones reales en orbita se debe utilizar esta por su estabilidad y mejor rango de distáncia para operaciones reales, por el simple echo que en el espacio el satelite no esta en juzgo de leyes de transmision de radio frequencias.

## Operaciones de testeo en tierra

1. Las primeras operaciones (outlab) fuera de laboratorio deben de ser hechas en espacios libres de interferencia por fuentes de radiofrequencia, como antenas de telefonia, retransmisores de radio, repetidores de ondas.

2. Los primeros testeos de altitude con uso de globo de Helio (He) deben ser hechos con los mismos asegurados por lineas de control, donde se podrá recuperar, subir y bajar de modo controlado y poder valorar medidas de campo.

3. Con seguridad de que se debe hacer un real lanzamiento de un globo de Helio (He) para comprobar sistemas y el prototipo se debe hacer cuando si tenga más de un protótipo testeado y aprobado por pelo menos 5 testeos con lo metodo anterior en dias distintos con condiciones meteorologicas distintas.

- a. Se debe consultar las leyes, legislaciones, permisos y condiciones del pais.
- b. Se debe pedir permiso y obtener el concenso de las autoridades.
- c. No se debe salir de los parametros de la ley.
- d. El prototipo debe estar atado a un paracaidas suficientemente fuerte que debe estar dentro del globo, de modo que cuando este esplote por la presión de altitud el prototipo no sea destruido en la caida y no sea capaz de crear ningun daño a terceros.
- e. Ya se debe poder rastrear y localizar el prototipo con precisión minima.
- f. Se debe ser capaz de capturar y guardar toda telemetria para estudo.
- g. Un veiculo de busqueda debe estar disponivel y acompañar las posiciones del globo.

## Tipos y categorias de satelites (cubesats o nanosats)

|   | 1U | 2U | 3U | 6U | 12U | 
| - | -  | -  | -  | -  | -   |
| L | 10cm | 10cm   | 10cm | 10cm | 20cm  |
| A | 10cm | 10cm   | 10cm | 20cm | 20cm  |
| P | 10cm | 20cm   | 30cm | 30cm | 30cm  |
| K | 1.3k | 2.6k   | 3.9k | 4.2k | 5.5k  |

```valores aproximados en peso y tamaño.```

- Segun la NASA las categorias son estas:

- - Satélites grandes: Más de 1.000 kg
- - Satélites medianos: 500-1.000 kg
- - Satélites pequeños:
- - Minisatélite: 100-500 kg
- - Microsatélite: 10-100 kg
- - Nanosatélite: 1-10 kg
- - Picosatélite: Menos de 1 kg

## Prestaciones de un nanosatelite y usos

1. Observación de la tierra

-  Recoger datos e interpretarlos es esencial para la gestión de los recursos naturales y el desarrollo de una economía sostenible. Analizar el impacto humano en agricultura, bosques, geología y medioambiente es crítico para la mejora de las condiciones de vida de la población.

- - Control de cultivos
- - - Los CubeSats tienen grandes aplicaciones en agricultura. La toma de imágenes permite la monitorización de cosechas y conocer qué zonas de un cultivo deberán regarse o abonarse más o menos, o cuáles están más secas. Los pequeños satélites ofrecen datos que sirven para estimar los daños provocados por fenómenos meteorológicos, pestes e infecciones.

- - Meteorología
- - - Los nanosatélites ofrecen previsiones meteorológicas precisas, muy útiles para industrias que se ven afectadas directamente por el clima. Asimismo, funcionan para detectar a tiempo desastres naturales o para luchar contra el cambio climático.

- - Monitorización de la actividad
- - - A través de las imágenes se pueden obtener datos relevantes a la actividad económica de una ciudad observando sus muelles de carga o aeropuertos. Un software de reconocimiento de aviones, barcos o contenedores de mercancías puede controlar el número de estos y mantener un histórico de exportaciones e importaciones.

2. Comunicaciones IoT

-  Los nanosatélites son la base del desarrollo del Internet de las Cosas (IoT) a nivel global, permitiendo comunicaciones con las zonas sin cobertura terrestre a través de una infraestructura espacial. Cada vez habrá más objetos sensorizados y redes con necesidad de comunicación a nivel planetario.

- - Mediciones inteligentes
- - - Los nanosatélites permiten la comunicación con máquinas y objetos, solo es necesario un identificador para el activo del que se desean tomar datos y conexión a Internet para recibir información: velocidad, de temperatura, de consumo de energía, etc. Estas mediciones inteligentes son fundamentales para predecir y tomar decisiones adecuadas.

- - Gestión remota
- - - Las tecnologías IoT permiten administrar todo tipo de activos desde cualquier lugar mediante software específico. Los satélites son los encargados de establecer esta comunicación con activos clave situados en áreas remotas y de entregar los datos que las empresas precisan para realizar su actividad y mejorar su eficiencia.

3. Geolocalización y logística

-  La gestión de activos (aviones, barcos, vehículos…) puede ser imposible o sumamente costosa  en zonas sin cobertura terrestre. Desde el espacio y con una visión global, una constelación de nanosatélites puede monitorizar a diferentes grupos de activos en cualquier parte del planeta de manera inmediata. Los nanosatélites pueden complementar las redes terrestres en actividades logísticas complejas.

- - Sistema ADS-B
- - - El sistema ADS-B (Automatic Dependent Surveillance – Broadcast) permite determinar la posición exacta de los aviones sin necesidad de señales procedentes de radares terrestres. Los datos que proveen los nanosatélites son fundamentales para garantizar el control y la seguridad de pasajeros y mercancías.

- - Control de barcos
- - - La comunicación entre nanosatélites y buques permite rastrear su posición exacta en tiempo real para controlar la situación y el estado de la mercancía. El rastreo de barcos aumenta la seguridad, para gestionar rutas, rescates, y evitar colisiones. Ayuda a prevenir la piratería, la pesca ilegal u otras actividades de vigilancia medioambiental.

- - Gestión de flotas
- - - Los sistemas de gestión de flotas son útiles para el seguimiento de vehículos de empresas de transporte de mercancías o de pasajeros, para empresas que cuentan con varios vehículos o para la Administración Pública. Los datos recogidos por los nanosatélites permiten un control exhaustivo y aportan datos para tomar decisiones que incrementen la productividad.

4. Monitorización de señales

-  Los nanosatélites permiten monitorizar las señales radio que se emiten desde la tierra. De este modo, por ejemplo, en caso de desastre se puede tener información preliminar sobre el grado de impacto y las zonas más afectadas permitiendo una organización más ágil de las labores de rescate y recuperación. 

- - SIGINT (Inteligencia de señal)
- - - Los nanosatélites son capaces de detectar las señales generadas por terceros. Los pequeños satélites permiten escuchar ciertas bandas de frecuencia, identificar emisiones procedentes tanto de la Tierra como del espacio y analizar el espectro electromagnético en esas bandas de frecuencias. Entre sus usos se encuentran el registro de emisiones no autorizadas, la detección de interferencias y la localización de su origen. La geolocalización de emisiones incluso es posible con aquellas que están cifradas pudiendo conocer su tipo de modulación y con qué ámbito podrían estar relacionadas. Así, por ejemplo, en caso de desastre natural, los nanosatélites permiten contar con información preliminar sobre el grado de impacto y las zonas más afectadas permitiendo una organización más ágil de las labores de rescate y recuperación. 

5. Aplicaciones científicas

-  Además de las soluciones comerciales, los CubeSats pueden emplearse para observación espacial, misiones interplanetarias, pruebas de sistemas en órbita o investigaciones biomédicas, así como ser una puerta de entrada para el desarrollo de programas espaciales de países que aún no hayan arrancado su carrera espacial. 

## Inversiones, inversores y capital

En un primer momento no esperamos utilizar modelos de Crowdfunding o otros modelos de arrecadación de recursos por el simples hecho de que planteamos en realidad que este proyecto sea profesional y cuente con inversores en modo startup o inversiones de capital para la formación de una empresa (CUBES) especializada en la creación de este tipo de nanosatelites.

Sabemos que salir de la etapa de prototipo hasta la empresa es un salto enorme, y por eso no tenemos pretensiones de tan pronto tener inversores, eso conllevaria plazos, presiones, maquetación a la marcha y lo que necesitamos antes de nada es tener un proyecto estable y viable para poder ofrecer al mercado alguna solución que sea factible y utilizable por futuros clientes.

Los costes de mantener un despacho con los equipos, personal, impuestos y cuentas en marcha no esta aun en nuestro alcance, por lo tanto en un futuro si que necesitamos de inversores, serios, comprometidos con este proyecto y personal calificado para los desarollos, es importante que toda tecnologia desarollada en este proyecto permanezca de manera confidencial y lejos de personas ajenas, por este motivo el repositorio debe permanecer privado y toda manufactura de construcción debe ser mantenida y desarollada internamente.

El precio para venta del desarollo a un cliente podria llegar a €200 mil euros, en consideración a cambios y especificaciones, esto es distinto del precio de lanzamiento del satelite que puede tener disparidades conforme se elije la empresa a que vá poner el satelite en orbita y el tipo de orbita, en SpaceX se puede llegar a lanzar (en este momento) un nanosatelite de tipo 1U por hasta €15 mil euros.

La vida util de un nanosatelite hoy es estimada en 5 hasta 15 años y eso depende de la tecnologia empleada y las protecciones de redundancia atribuidas al proyecto, este tiempo util y su bajo precio hacen aceptables los lanzamientos programados a cada 5 años con los beneficios que se puede obtener.

## Maquetación actual

![Screenshot](https://github.com/davidsnege/CUBES/blob/main/img/schemas/esquematico_montagen.jpg?raw=true)
![Screenshot](https://github.com/davidsnege/CUBES/blob/main/3D/Cubes%20Frame/Cubes%20Frame.png?raw=true)
![Screenshot](https://github.com/davidsnege/CUBES/blob/main/3D/Cubes%20Mounted%20Frame/Cubes%20Frame%20Mounted.png?raw=true)
![Screenshot](https://github.com/davidsnege/CUBES/blob/main/3D/Cubes%20Drawer/Cubes%20Drawer.png?raw=true)
![Screenshot](https://github.com/davidsnege/CUBES/blob/main/3D/Cubes%20Mounted%20Frame/Cubes%20Frame%20Mounted%20and%20Drawer.png?raw=true)
