<h1 align="center">⚔️ Console Dungeon Crawler</h1>

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-20-blue.svg" alt="C++ Version">
  <img src="https://img.shields.io/badge/Platform-Windows%20%7C%20macOS%20%7C%20Linux-lightgrey.svg" alt="Platform">
  <img src="https://img.shields.io/badge/License-MIT-green.svg" alt="License">
</p>

<p align="center">
  <b>Console Dungeon Crawler</b> to klasyczna gra typu <i>roguelike</i> napisana w C++20. 
  Projekt skupia się na eksploracji lochów, turowej walce oraz minimalistycznej oprawie tekstowej.
</p>

<hr>

<h2>O projekcie</h2>
<p>
  Głównym celem tego projektu jest demonstracja umiejętności programowania obiektowego w C++ oraz biegłości w pracy z systemem kontroli wersji <b>Git</b> w zespole dwuosobowym.
</p>

<h3>Struktura Projektu (OOP)</h3>
<ul>
  <li><b>Core/</b> — Główny silnik gry (Game Loop, Input Handler).</li>
  <li><b>Entities/</b> — Klasy postaci (Player, Enemy, Entity).</li>
  <li><b>World/</b> — System mapy i kolizji.</li>
</ul>

<hr>

<h2>Sterowanie</h2>
<table align="center">
  <tr>
    <th>Klawisz</th>
    <th>Akcja</th>
  </tr>
  <tr>
    <td align="center"><b>W</b></td>
    <td>Ruch w górę</td>
  </tr>
  <tr>
    <td align="center"><b>S</b></td>
    <td>Ruch w dół</td>
  </tr>
  <tr>
    <td align="center"><b>A</b></td>
    <td>Ruch w lewo</td>
  </tr>
  <tr>
    <td align="center"><b>D</b></td>
    <td>Ruch w prawo</td>
  </tr>
  <tr>
    <td align="center"><b>Q</b></td>
    <td>Wyjście z gry</td>
  </tr>
</table>

<hr>

<h2>Legenda Mapy</h2>
<table>
  <thead>
    <tr>
      <th>Symbol</th>
      <th>Znaczenie</th>
      <th>Opis</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code style="color: green">@</code></td>
      <td><b>Gracz</b></td>
      <td>Twoja postać (Zielony)</td>
    </tr>
    <tr>
      <td><code style="color: red">E</code></td>
      <td><b>Przeciwnik</b></td>
      <td>Przeciwnik (Czerwony)</td>
    </tr>
    <tr>
      <td><code style="color: gray">#</code></td>
      <td><b>Ściana</b></td>
      <td>Przeszkoda (Szary)</td>
    </tr>
    <tr>
      <td><code style="color: gold">></code></td>
      <td><b>Wyjście</b></td>
      <td>Cel gry (Złoty)</td>
    </tr>
  </tbody>
</table>

<hr>

<h2>Instalacja i Kompilacja</h2>

<p>Projekt korzysta z systemu <b>CMake</b> (min. wersja 4.2). Aby skompilować grę, użyj poniższych komend:</p>

<<<<<<< HEAD
<pre>
# 1. Stwórz katalog dla plików budowy
mkdir build
cd build

# 2. Skonfiguruj projekt
cmake ..

# 3. Skompiluj kod
make

# 4. Uruchom grę
./projektWasilkowski

# 5. Uruchom testy
./run_tests
</pre>
=======
### Wymagania
* Kompilator C++ wspierający standard **C++20** (np. GCC 10+, Clang 10+, MSVC 2019+).
* **CMake** (wersja 3.14 lub nowsza).
* Biblioteka **SFML** (zostanie pobrana automatycznie przez CMake).

### Instrukcja kompilacji
1. **Sklonuj repozytorium:**
   ```bash
   git clone https://github.com/twoj-login/dungeon-crawler.git
   cd dungeon-crawler
   ```

2. **Skonfiguruj projekt za pomocą CMake:**
   ```bash
   mkdir build
   cd build
   cmake ..
   ```

3. **Skompiluj kod:**
   ```bash
   cmake --build .
   ```

4. **Uruchom grę:**
   ```bash
   ./projektWasilkowski
   ```

### Uruchamianie testów
Aby uruchomić testy jednostkowe:
```bash
./run_tests
```
</details>
>>>>>>> 1763d7c (fix: prevent negative HP values)

<hr>

<h2>Zespół</h2>
<p>Projekt został zrealizowany przy użyciu modelu <b>Feature Branching</b>.</p>
<ul>
  <li><b>Herman Papko</b> — Silnik graficzny, system mapy, UI.</li>
  <li><b>Darya Parusava</b> — Logika walki, system bytów.</li>
</ul>

<p align="right"><i>Projekt stworzony na potrzeby zaliczenia przedmiotu Programowanie C++.</i></p>
