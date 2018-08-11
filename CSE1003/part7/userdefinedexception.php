<?php
class InvalidUIDException extends Exception {
    private $invalidUID;
    // redefine exception
    public function __construct($message, $invalidUID) {
        $this->invalidUID = $invalidUID;
        parent::__construct($message);
    }

    // overriding toString method
    public function __toString() {
        return $this->message;
    }

    public function detail() {
        echo $this->invalidUID." is an invalid UID.";
    }
}

// assuming input from GET
// $inputUID = $_GET['uid'];
$inputUID = 'S12345678901';
$inputUID2 = 'V1678901';

function isValidUID($uid) {
    $uid = strval($uid);
    if(strlen($uid) === 12 && substr($uid, 0, 1) === 'S') return true;
    else throw new InvalidUIDException('UID not valid.', $uid);
}

try {
    echo (isValidUID($inputUID) ? "OK, Valid\n" : "");
    echo (isValidUID($inputUID2) ? "OK, Valid\n" : "");
}
catch(InvalidUIDException $ex) {
    echo $ex->getMessage()." ";
    $ex->detail();
}
echo "\n";
