echo -n "Enter file name: ";
read filename;

file_exists=$([ -w $filename ] && echo true);

if [ "$file_exists" != true ]
then
    echo "File dosent exist, creating new file...";
    touch $filename;
    echo "Created file $filename";
fi

echo "Enter text to append to the file: ";
read text;

echo $text >> $filename;
echo "File content ->"
cat $filename;