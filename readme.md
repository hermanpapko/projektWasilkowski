<h1 align="center">⚔️ Console Dungeon Crawler</h1>

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-11%2B-blue.svg" alt="C++ Version">
  <img src="https://img.shields.io/badge/Platform-Windows-lightgrey.svg" alt="Platform">
  <img src="https://img.shields.io/badge/License-MIT-green.svg" alt="License">
</p>

<p align="center">
  <b>Console Dungeon Crawler</b> to klasyczna gra typu <i>roguelike</i> napisana w języku C++. 
  Projekt skupia się na eksploracji lochów, turowej walce oraz zbieraniu skarbów w minimalistycznej oprawie tekstowej.
</p>

<hr>

<h2>O projekcie</h2>
<p>
  Głównym celem tego projektu jest demonstracja umiejętności programowania obiektowego w C++ oraz biegłości w pracy z systemem kontroli wersji <b>Git</b> w zespole dwuosobowym.
</p>

<h3>Główne funkcje</h3>
<ul>
  <li><b>Proceduralna interakcja:</b> dynamiczne reagowanie świata na ruchy gracza.</li>
  <li><b>System walki:</b> turowa wymiana ciosów z przeciwnikami.</li>
  <li><b>Zarządzanie zasobami:</b> zbieranie mikstur leczniczych i złota.</li>
  <li><b>Log zdarzeń:</b> powiadomienia o akcjach w czasie rzeczywistym.</li>
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
      <td><code>@</code></td>
      <td><b>Gracz</b></td>
      <td>Twoja postać</td>
    </tr>
    <tr>
      <td><code>E</code></td>
      <td><b>Przeciwnik</b></td>
      <td>Przeciwnik, który może Cię zaatakować</td>
    </tr>
    <tr>
      <td><code>#</code></td>
      <td><b>Ściana</b></td>
      <td>Nieprzekraczalna przeszkoda</td>
    </tr>
    <tr>
      <td><code>+</code></td>
      <td><b>Apteczka</b></td>
      <td>Mikstura przywracająca HP</td>
    </tr>
  </tbody>
</table>

<hr>

<h2>Instalacja i Kompilacja</h2>

<details>
<summary><b>Kliknij, aby rozwinąć instrukcję</b></summary>

<pre>
# 1. Sklonuj repozytorium
git clone https://github.com/twoj-login/dungeon-crawler.git

# 2. Skompiluj kod
g++ main.cpp -o DungeonGame.exe

# 3. Uruchom grę
./DungeonGame.exe
</pre>
</details>

<hr>

<h2>Zespół</h2>
<p>Projekt został zrealizowany przy użyciu modelu <b>Feature Branching</b>.</p>
<ul>
  <li><b>Herman Papko</b> Silnik graficzny, system mapy.</li>
  <li><b>Darya Parusava</b> Logika walki, system przedmiotów.</li>
</ul>

<p align="right"><i>Projekt stworzony na potrzeby zaliczenia przedmiotu Programowanie C++.</i></p>