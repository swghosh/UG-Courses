<?php
class Text {
    private $textString;
    function __construct($textString) {
        $this->textString = $textString;
    }
    public function getTextString() {
        return $this->textString;
    }
}
class RichText extends Text {
    private $bold = false, $italic = false, $underline = false;
    function __construct($textString, $bold, $italic, $underline) {
        $this->bold = $bold;
        $this->italic = $italic;
        $this->underline = $underline;
        parent::__construct($textString);
    }
    // @ Override
    public function getTextString() {
        $richTextString = parent::getTextString();
        if($this->bold) {
            $richTextString = "<b>$richTextString</b>";
        }
        if($this->italic) {
            $richTextString = "<i>$richTextString</i>";
        }
        if($this->underline) {
            $richTextString = "<u>$richTextString</u>";
        }
        return $richTextString;
    }
}

$myText = new Text("This is a sample text.");
$myBoldRichText = new RichText("This is bold sample text.", true, false, false);
$myItalicRichText = new RichText("This is italic sample text.", false, true, false);
$myUnderlineRichText = new RichText("This is underlined sample text.", false, false, true);
$mySpecialRichText = new RichText("This is bold, italic, underlined sample text.", true, true, true);

echo $myText->getTextString()."<br>".$myBoldRichText->getTextString()."<br>".$myItalicRichText->getTextString()."<br>".$myUnderlineRichText->getTextString()."<br>".$mySpecialRichText->getTextString();