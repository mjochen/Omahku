# Project.h

- [x] Interessante keuze om drukknoppen in het Nederlands af te korten (DK) en de andere twee in het Engels...

      This has been fixed.
- [x] Ik ben op zich wel fan van defines, maar zou het ook niet handig zijn moest je die in een array krijgen? Zo kan je ze een stuk makkelijker "allemaal ineens als input zetten" of "allemaal nakijken" (in de mate dat dat nodig is). Nu moet je bij een extra knop niet alleen een extra define maken, maar ook heel je code nakijken om te zien of je overal de nieuwe knop hebt toegevoegd.

      Het kan zijn dat ik jouw opmerking fout lees. De bedoeling van de defines is vooral je hebt de fysieke knoppen van je huis, die map je zo op naam met de juiste input. Daarna voeg je die knopnaam toe aan de juiste uitgang met de addInput() functie. Zo map je de knop aan de uitgang uiteindelijk. Instellen als ingang, etc. gebeurt allemaal automatisch achter de schermen. addInputs() is nu een extra functie met array als input ipv 1 individuele input.

      In mijn hoofd had ik een array, en als het daarin terecht komt is het een knop en wordt hij nadien automatisch gelinkt. Maar je hebt gelijk, de best wel noodzakelijke "aan wat dan" moet later nog komen. Waarmee je oplossing inderdaad wel proper is, want dat linken doen we dan door de definitie aan te maken in het programma wat dubbel op is (mijn punt) maar wel nuttig (en dat had ik gemist).

# App.cpp

- [x] Heb ik het goed dat "addInput" de knop aan een uitgang toevoegt en "addAllOutInput" de alles uit is?

      Dat klopt helemaal.

      Maak je er dan "AllOffInput" van? "Out" is een ander soort uit dan "Off"...
      Klopt het trouwens dat we hiermee bepaalde uitgangen van de alles uit kunnen afkoppelen? Want dat zou goed zijn.

      Done. Klopt, je kan per output specifieren of je daar de all-off functie op wilt hebben. Je kan hier ook groepen van maken in de `config.h` en dan gebruiken in de `addAllOutInputs(array, size);` bijvoorbeeld.

- [x] De code in app.cpp ziet er heerlijk compact uit, met alle echte logica weggestopt. Als je dat kan volhouden komt het zeker goed.
- [x] Wel wat verwarrend: het relais koppel je in App.h, maar de knoppen in App.cpp...

      This has also been fixed.

- Ik heb nog iets nieuws bedacht (maar het is een nice to have): Voor uitgangen die hoog vermogen kunnen trekken (buitenverlichting, stekkers) stuur ik nu een contactor (een relais dat werkt zoals een licht moet werken). Dat is een dubbelpolige contactor, en de tweede pool gebruik ik om 24v terug in de PLC te brengen. Zo weet de PLC dat het licht aan of uit is.
Maar in code wordt er niks mee gedaan, en één contactor stond aan toen ik de laatste keer de PLC's heb uitgezet. Daardoor gaat die stekker aan als ik op de alles-uit duw. (Wat geen probleem is want er hangt niks op.) Maar als je daarmee rekening kan houden zou dat ook tof zijn.
(Op zich is de nood wel minder groot: de PLC's van nu hebben ook laag-vermogen relais', en die zijn niet te vervangen. De goedkope Chinese die er nu aanhangen zijn goedkoop, en ook gewoon te vervangen met een soldeerbout.)