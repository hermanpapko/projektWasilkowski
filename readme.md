<h1 align="center">⚔️ SFML Dungeon Crawler</h1>

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-20-blue.svg" alt="C++ Version">
  <img src="https://img.shields.io/badge/Platform-Windows%20%7C%20macOS%20%7C%20Linux-lightgrey.svg" alt="Platform">
  <img src="https://img.shields.io/badge/Library-SFML%202.6-green.svg" alt="SFML Version">
  <img src="https://img.shields.io/badge/License-MIT-green.svg" alt="License">
</p>

<p align="center">
  <b>SFML Dungeon Crawler</b> to gra typu <i>roguelike</i> napisana w <b>C++20</b>. 
  Projekt przeszedł gruntowną aktualizację i obecnie wykorzystuje bibliotekę <b>SFML</b> do renderowania okienkowego, zastępując wcześniejszą, czysto konsolową oprawę wizualną.
</p>

<hr>

<h2>O projekcie</h2>
<p>
  Głównym celem tego projektu jest demonstracja umiejętności programowania obiektowego (OOP) w C++ oraz biegłości w pracy zespołowej z wykorzystaniem systemu <b>Git</b>. Gra zawiera system poziomów, walki z przeciwnikami, log zdarzeń oraz zoptymalizowane renderowanie mapy oparte na bibliotece SFML.
</p>

<h3>Struktura Projektu</h3>
<ul>
  <li><b>Core/</b> — Główny silnik gry (Game Loop, Input Handler, renderowanie w oknie).</li>
  <li><b>Entities/</b> — Klasy bytów (gracz z systemem poziomów i punktacją, przeciwnicy).</li>
  <li><b>World/</b> — System zarządzania mapą i kolizjami, zoptymalizowane rysowanie (Vertex Array).</li>
</ul>

<hr>

<h2>Sterowanie</h2>
<table align="center">
  <tr>
    <th>Klawisz</th>
    <th>Akcja</th>
  </tr>
  <tr>
    <td align="center"><b>W / Strzałka w górę</b></td>
    <td>Ruch w górę</td>
  </tr>
  <tr>
    <td align="center"><b>S / Strzałka w dół</b></td>
    <td>Ruch w dół</td>
  </tr>
  <tr>
    <td align="center"><b>A / Strzałka w lewo</b></td>
    <td>Ruch w lewo</td>
  </tr>
  <tr>
    <td align="center"><b>D / Strzałka w prawo</b></td>
    <td>Ruch w prawo</td>
  </tr>
  <tr>
    <td align="center"><b>ESC / Q</b></td>
    <td>Wyjście z gry</td>
  </tr>
</table>

<hr>

<h2>Wymagania</h2>
<ul>
  <li>Kompilator C++ wspierający standard <b>C++20</b> (np. GCC 10+, Clang 10+, MSVC 2019+).</li>
  <li><b>CMake</b> (wersja 3.14 lub nowsza).</li>
  <li>Zależności <b>SFML</b> (wersja 2.6.x) zostaną pobrane i skonfigurowane w pełni automatycznie podczas budowania projektu (dzięki <code>FetchContent</code>). Na systemach Windows biblioteka linkuje się statycznie, zapewniając gotowy, łatwo przenaszalny plik <code>.exe</code> bez dodatkowych bibliotek DLL.</li>
</ul>

<hr>

<h2>Instalacja i Kompilacja</h2>

<p>Projekt korzysta z systemu <b>CMake</b>. Postępuj zgodnie z poniższymi krokami:</p>

<pre>
# 1. Sklonuj repozytorium (lub wejdź do katalogu projektu)
git clone https://github.com/twoj-login/projektWasilkowski.git
cd projektWasilkowski

# 2. Stwórz katalog dla plików budowy i przejdź do niego
mkdir build
cd build

# 3. Skonfiguruj projekt
cmake ..

# 4. Skompiluj kod
cmake --build .

# 5. Uruchom grę
./projektWasilkowski
</pre>

<h3>Uruchamianie testów</h3>
<p>W projekcie znajdują się testy jednostkowe. Aby je uruchomić, użyj polecenia (będąc w utworzonym katalogu <code>build</code>):</p>
<pre>
./run_tests
</pre>

<hr>

<h2>Zespół</h2>
<p>Projekt został zrealizowany przy użyciu modelu <b>Feature Branching</b>.</p>
<ul>
  <li><b>Herman Papko</b> — Silnik graficzny i obsługa okna (SFML), mechanika mapy i interfejs UI.</li>
  <li><b>Darya Parusava</b> — Logika i mechanika walki, rozbudowa systemu klas Entities, blokada ujemnego HP, komentarze strukturalne Doxygen.</li>
</ul>

<p align="right"><i>Projekt stworzony na potrzeby zaliczenia przedmiotu Programowanie C++.</i></p>