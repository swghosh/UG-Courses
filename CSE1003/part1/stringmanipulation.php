<?php
// assuming that the string is read from GET
$userInputString = $_GET['string'];

/* create a parses that is able to parse html like this
 * eg.
 * input: tagname1(tagname2(content1), tagname3(tagname4(content2)))
 * output: <tagname1><tagname2>content1</tagname2><tagname3><tagname4>content2</tagname4></tagname3></tagname1>
 * eg.
 * input: html(head(title(Hello page)), body(h1(Hello)))
 * output: <html><head><title>Hello page</title></head><body><h1>Hello</h1></body></html>
 */
function parseAsHTML($formattedString) {
    $formattedString = trim($formattedString);
    $firstBracketIndex = strpos($formattedString, '(');
    if(!$firstBracketIndex) {
        return $formattedString;
    }
    $lastBracketIndex = strrpos($formattedString, ')');
    
    $tagName = substr($formattedString, 0, $firstBracketIndex);
    $content = substr($formattedString, $firstBracketIndex + 1, $lastBracketIndex - $firstBracketIndex - 1);

    $contents = explode(',', $content);
    $parsed = "";
    for($index = 0; $index < count($contents); $index++) {
        $parsed = $parsed.parseAsHTML($contents[$index]);
    }
    return "<$tagName>$parsed</$tagName>";
}

echo parseAsHTML($userInputString);