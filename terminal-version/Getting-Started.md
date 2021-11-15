<h1>Getting Started</h1>

<p>
    You Can Create Any Type of Mounter that you want, but first you have define the json file.
</p>

<h3>
    How Create The Json File?
</h3>

<p>You must define:</p>
<ul>
    <li>"bitset": Bits from processor</li>
    <li>"fields": Fields that can compose one word</li>
    <li>"opcode" on "fields": Bits that describes how many instructions you have, 3bits describes 2³ instructions</li>
    <li>"struct_inst":  Instructions Type</li>
    <li>"instruction": Each instruction name and its structure</lo>
</ul>
<br>
<p>Use "zepto16.json" to know how to build an assembly mounter.</p>
<br>
<p>!! Using "null"+number, you can define null fields with "number" bits</p>
<br>
<p>How Compile the example?</p>
<code>g++ asmMounterZepto16.cpp -o main -O2 -Wall -std=c++17 -lm</code>
</br>
<p>To Execute:</p>
<code>./main</code>