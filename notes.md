# Project.h

- [x] Interessante keuze om drukknoppen in het Nederlands af te korten (DK) en de andere twee in het Engels...

      This has been fixed.
- [x] Ik ben op zich wel fan van defines, maar zou het ook niet handig zijn moest je die in een array krijgen? Zo kan je ze een stuk makkelijker "allemaal ineens als input zetten" of "allemaal nakijken" (in de mate dat dat nodig is). Nu moet je bij een extra knop niet alleen een extra define maken, maar ook heel je code nakijken om te zien of je overal de nieuwe knop hebt toegevoegd.

      Het kan zijn dat ik jouw opmerking fout lees. De bedoeling van de defines is vooral je hebt de fysieke knoppen van je huis, die map je zo op naam met de juiste input. Daarna voeg je die knopnaam toe aan de juiste uitgang met de addInput() functie. Zo map je de knop aan de uitgang uiteindelijk. Instellen als ingang, etc. gebeurt allemaal automatisch achter de schermen. addInputs() is nu een extra fucntie met array als input ipv 1 individuele input.

# App.cpp

- [x] Heb ik het goed dat "addInput" de knop aan een uitgang toevoegt en "addAllOutInput" de alles uit is?

      Dat klopt helemaal.
- [x] De code in app.cpp ziet er heerlijk compact uit, met alle echte logica weggestopt. Als je dat kan volhouden komt het zeker goed.
- [x] Wel wat verwarrend: het relais koppel je in App.h, maar de knoppen in App.cpp...

      This has also been fixed.