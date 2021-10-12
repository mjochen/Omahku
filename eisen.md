# Controller

* Mag Arduino zijn, maar dat staat niet in steen. Je mag alternatieven voorstellen.
    * Ook een optie: ESP32 met 4x MCP23017 (of gelijkaardig) over I²C.
    * Ik heb MCP23017-modules besteld, maar die zijn er nog niet
    * In de ideale wereld werken de twee systemen (arduino en ESP32) naast elkaar
* Hangen aan het netwerk met ENC28J60 module (of Ethernet Shield).
    * Krijgt IP via DHCP, hostname instelbaar via code.
    * Er is WiFi, moest je voor ESP32 willen gaan.
* Er kunnen meerdere controllers tegelijk gebruikt worden:
    * 2 in de kast
    * 1 op de zolder
    * 1 in de garage
    * …
* Die controllers kunnen mekaar aansturen via MQTT
    * Knop op A stuurt licht op B en omgekeerd
* Maar meestal hangen in- en uitvoer op dezelfde controller, en moeten die blijven werken wanneer MQTT niet meer werkt.
* Het enige protocol dat er zeker in moet: MQTT. Er draait een lokale server.
    * (Tenzij je kan motiveren om daar een alternatief voor te kiezen.)
    * Onderwerp: naam_arduino/[light, sensor, …]/naam_actuator
    * Of…
* Programmatie moet makkelijk te doen zijn (liefst library die alles afhandelt).
* Zo veel mogelijk gebruik van bestaande libraries.
* Nice to have: lichten terug in vorige staat na stroomstoring.
* Programmeren via platform_IO, alles op github-repo

# Uitgangen

* Het licht moet altijd blijven werken, ook als alle computers afstaan. De link tussen knop en lamp moet dus over 1 controller (een arduino, een esp…) lopen.
* Sommige lampen vallen uit na X-aantal tijd.
    * Tijd is instelbaar, liefst via een MQTT maar via code mag ook.
    * Als de tijd via MQTT instelbaar is blijft hij ook bewaard na stroomuitval
* Per lamp: MQTT boodschap bij verandering en poll (vraag vanuit server waarop ze hun status geven).
* Lampen oprit: per 3, moeten kunnen knipperen (landingsbaan-effect)
    * Werkt al op een ESP, aangestuurd via MQTT
    * Op die ESP hangt ook een ultrasoon sensor voor de meting van regenwater
    * Je mag die ESP mee opnemen in het project of zien als een MQTT-luisteraar
* Mogelijke uitbreidingen:
    * Dimmers: uitgang via PWM, ingang via HA of…
        * Open voor suggesties over aansturen van een dimmer met knoppen, rotary encoder, ...
    * Led-controllers: via aparte controller, aan te sturen met knop via MQTT (en via HA)
        * Open voor suggesties van een goeie LED-controller
    * Tasmota-switches: via aparte controller, aan te sturen met knop via MQTT (en via HA)
* Garagepoort: korte puls is "start motor". Instelling via HA is gewenst open of dicht (idealiter). Wat als poort halverwege blijft staan?

# Ingangen/sensoren

* Knoppen: de meeste zijn impulscontacten (Kort drukken aan, kort drukken uit.)
* Bewegingsmelders: lamp brandt zolang knop is "ingedrukt".
    * Let op, lampen die aan bewegingsmelders hangen kunnen ook aan- en uitgezet worden met een knop (het terras: springt automatisch aan maar kan ook aangezet worden) of springt aan als een andere knop wordt verzet (verlichting hal springt aan als licht op zolder wordt uitgezet)
* Er is ook een alles-uit-knop.
* Knoppen komen normaal niet naar buiten via MQTT, maar dat kan wel
    * Bijvoorbeeld een knop voor een tasmota-switch via MQTT
    * Bijvoorbeeld een bewegingsmelder
* Sensoren: geven een 1 of 0. Moeten via MQTT een boodschap geven bij verandering en poll.
* Zijn er al:
    * Garagepoort open of dicht (twee reed-contacten per poort, dus ook melding als die halverwege staan)
    * Deur kelder los of vast (limit switch met NC en NO, beiden doorgelust naar de kast)
    * Deur kelder gesloten (enkel reed-contact)
    * Dieptemeting in de regenput via ultrasoon-sensor
* Moeten er ooit komen:
    * Automatische uitlezing van de meters (niet nodig voor de controller, wel voor de HA)
    * Passagemelder op de oprit (sturen eventueel lichten aan)
    * Weerstation (niet nodig voor de controller, wel voor HA)

# Website

* Home Assistant of een alternatief
* Alle lichten aansturen, feedback geven per kamer
* Alleen intern of via VPN bereikbaar (een goeie security-checkup mag ook altijd)
* Draait op server in VM (geen Pi voorzien)
* Is ook niet de focus van dit project, ik wil vooral werkende controllers en eventueel een basis HA-configuratie erbij
    * Zie ook de Mycroft die Frederik misschien in orde ging brengen

# Nice to have

* E-ink display die een overzicht van het huis geeft, met de knopjes bovenaan wisselen tussen de verdiepingen/kamers
    * https://www.aliexpress.com/item/1005002272417292.html?spm=a2g0s.9042311.0.0.62174c4dCJOf3d
