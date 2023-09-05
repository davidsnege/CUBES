# CUBES
CUBES  - Comunicaciones Unificadas Basadas en Espacio y Satelites - ESPAÑA 

![Screenshot](https://github.com/davidsnege/CUBES/blob/main/img/blanco.png)

## Objectivos

- Estudiar y aprender todo posible para comunicaciones de larga distáncia con arduino en RF.
- Conocer todos modulos y sensores que sean utiles en un entorno de baja orbita o orbita estacionaria.
- Probar con acelerometros y medios de estabilización y maniobras a cero gravedad.
- Crear librerias proprias para el proyecto.
- Probar modulos de camara para captura de imagenes y su envio.
</p>
https://www.arducam.com/tag/arducam-mini/</p>
https://search.arduino.cc/search/?q=camera&tab=store</p>
</p>

- Probar con GPS precision de localización y orientación geo.
- Crear un protótipo funcional del case cubesat para nuestro proyecto de 1U.
- Hacer pruebas con globos de hélio para rastreo y envio de datos.
- Verificar el concepto de satelite globo.
- Verificar el concepto de globo estacionario.
- Verificar el concepto de globo dirigido.
- Estudiar las proteciones requeridas en los equipos para protección de radiación en ambiente fuera de atmosfera.
- Estudiar los usos de nano satelites para agricultura, medio ambiente y monitoreo de areas de risco y demas aplicaciones.
- Documentar y prototipar un satelite funcional final que pueda tener uso comercial en un futuro.

### Uso de Arduino (Nano, Mini, o similares)

- Las capacidades de transmisión a distancia de cada modulo de radio va a ser probada y aferida.
- Las capacidades de usar modulos o componentes mini o sus respectivos chips para usar menor espacio y peso seran valoradas.
- La capacidade de enviar paquetes de datos debe ser fiable aunque en pequeños paquetes.
- Se debe tener en cuenta las capacidades de uso de antenas del tipo retractil o tipo origami.
- Las capacidades de carga solar, baterias, y larga duracción ininterupta de las operaciones debe ser valorada.
- Se debe probar con distintos metodos ya probados de acelerometros para estabilidad.
- Se debe probar la capacidad de envio de imagenes en paquetes unicos.
- Se debe probar la capacidad de criptografia en tiempo para envio de datos.
- Se debe probar la capacidad de operación remota y configuración por radio.
- Se debe poder geolocalizar por GPS el modulo en tiempo integral.
- Se debe probar comunicaciones por GPRS/HSPD/GSM para todos tipos de envios de datos.

### Arduino - Componentes Testeados
| Modulo/Componente  | Tipo                                 | Testeado          | Resultado         | Observaciones                             | Limitaciones                             |
| ------------------ | ------------------------------------ | ----------------- | ----------------- | ----------------------------------------- | ---------------------------------------- |
| NRF24L01           | :artificial_satellite: :satellite:   | :heavy_check_mark:| :3rd_place_medal: | No soporta largas distancias y obstaculos | 500mts Limite aferido                    |
| L.O.R.A            | :artificial_satellite: :satellite:   | :lady_beetle:     | :2nd_place_medal: | Necesita mas testeo en diferentes confg.  | Errores de comunicación, Buen Rango 18km |
| OV7675 ARDUCAM     | :eyeglasses: :camera:                | :x:               | :3rd_place_medal: | N/A                                       | N/A                                      |

:flying_saucer:
:rocket:
:artificial_satellite:
:satellite:
:computer:
:compass:

:eyeglasses:
:heavy_check_mark:
:lady_beetle:
:x:

:trophy:
:1st_place_medal:
:2nd_place_medal:
:3rd_place_medal:

### Budget / Money / Pasta
- Disponible / Mes = €15

### Plazos y Conclusión
- Indefinido / Basado en €€€€ Disponible -VS- Tiempo disponible para el proyecto

### Personas en el proyecto
- David Belleti Snege

#### Referencias y Links 
- - https://www.nasa.gov/directorates/heo/home/CubeSats_initiative
- - https://en.wikipedia.org/wiki/CubeSat
- - https://es.wikipedia.org/wiki/ArduSat
- - https://programarfacil.com/podcast/tiny-gs/
- - https://nanoavionics.com/cubesat-components/
- - https://www.dk3wn.info/wp/satelliten/ardusat-1-2-x/
- - https://galopago.github.io/espanol/lora-satelite-estacion-terrena/
- - https://github.com/McOrts/taller-lora-sat-groundstation
- - https://granasat.ugr.es/category/granasat/cubesat-esp/
- - https://prezi.com/8d2tanljbit7/ardusat-an-arduino-based-cubesat/
- - https://ui.adsabs.harvard.edu/abs/2015ESASP.730..643G/abstract
- - https://www.mokolora.com/es/lora-satellite-for-iot-connectivity/
- - https://www.mokosmart.com/es/lorawan-iot-used-in-satallite/
- - https://www.echostarmobile.com/wp-content/uploads/2022/05/Remote-Monitoring-of-Renewable-Energy-Sites-Echostar-Mobile-Whitepaper-Spanish.pdf
- - https://alen.space/es/pequenos-satelites-para-servicios-iot/
- - https://sdr-es.com/recibir-satelites-LoRa-con-tinyGS/
- - https://blog.bricogeek.com/noticias/tecnologia/tecnologia-espanola-para-lanzar-el-mini-satelite-fossasat-1-para-crear-una-red-lora-global/

