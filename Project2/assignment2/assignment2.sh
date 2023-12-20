# !/bin/bash

#Anthony Tran
#CS 3377.005

#read in input file
read -p "Enter the filename: " fileName

#check if file exists
if [ ! -e "$fileName" ]; then
    echo "$fileName does not exist."
    exit 1
fi

#clear output.txt
> output2.txt

#create array of possible date patterns
patterns=( "\d{1,2}[/\\]\d{1,2}[/\\]\d{2,4}" #02/23/2002
"\d{1,2}-\d{1,2}-\d{2,4}" #02-23-2002 2-23-2002
"\d{1,2}\.\d{1,2}\.\d{2,4}" #2.23.2002
"\d{4}[/\\\-\. ]\d{1,2}[/\\\-\. ]\d{1,2}"
"([Jj]anuary|[Ff]ebruary|[Mm]arch|[Aa]pril|[Mm]ay|[Jj]une|[Jj]uly|[Aa]ugust|[Ss]eptember|[Oo]ctober|[Nn]ovember|[Dd]ecember) \d{1,2},? ?\d{4}"
"\d{1,2} ([Jj]anuary|[Ff]ebruary|[Mm]arch|[Aa]pril|[Mm]ay|[Jj]une|[Jj]uly|[Aa]ugust|[Ss]eptember|[Oo]ctober|[Nn]ovember|[Dd]ecember),? \d{4}"
"\d{4},? ([Jj]anuary|[Ff]ebruary|[Mm]arch|[Aa]pril|[Mm]ay|[Jj]une|[Jj]uly|[Aa]ugust|[Ss]eptember|[Oo]ctober|[Nn]ovember|[Dd]ecember) \d{1,2}"
"([Tt]he )?\d{1,2}(st|nd|rd|th) of ([Jj]anuary|[Ff]ebruary|[Mm]arch|[Aa]pril|[Mm]ay|[Jj]une|[Jj]uly|[Aa]ugust|[Ss]eptember|[Oo]ctober|[Nn]ovember|[Dd]ecember)(, \d{4}| \d{4})?"
"([Jj]an|[Ff]eb|[Mm]ar|[Aa]pr|[Mm]ay|[Jj]un|[Jj]ul|[Aa]ug|[Ss]ep|[Oo]ct|[Nn]ov|[Dd]ec) \d{1,2},? \d{4}"
"\d{1,2} ([Jj]an|[Ff]eb|[Mm]ar|[Aa]pr|[Mm]ay|[Jj]un|[Jj]ul|[Aa]ug|[Ss]ep|[Oo]ct|[Nn]ov|[Dd]ec),? \d{4}"
"\d{4},? ([Jj]an|[Ff]eb|[Mm]ar|[Aa]pr|[Mm]ay|[Jj]un|[Jj]ul|[Aa]ug|[Ss]ep|[Oo]ct|[Nn]ov|[Dd]ec) \d{1,2}"
"([Jj]anuary|[Ff]ebruary|[Mm]arch|[Aa]pril|[Mm]ay|[Jj]une|[Jj]uly|[Aa]ugust|[Ss]eptember|[Oo]ctober|[Nn]ovember|[Dd]ecember) \d{1,2}(st|nd|rd|th)(, \d{4}| of ’\d{2})?"
"([Jj]anuary|[Ff]ebruary|[Mm]arch|[Aa]pril|[Mm]ay|[Jj]une|[Jj]uly|[Aa]ugust|[Ss]eptember|[Oo]ctober|[Nn]ovember|[Dd]ecember) \d{1,2}(st|nd|rd|th) (\[morning] )?of \d{4}"
)

#create counter of dates
dates=0

#loop through each pattern in patterns and see if it matches any date in file
for pattern in "${patterns[@]}"; do
    found=$(grep -oE "$pattern" "$fileName")
    counter=$(echo "$found" | wc -l)
    echo "$found" >> output2.txt
    dates=$((dates + counter))
done

#count empty lines
empty_line=$(grep -E '[^[:space:]]' "$fileName" | wc -l)
dates=$((dates - empty_line))
grep . "output2.txt" > "output.txt"

#print total number of dates
line_count=$(wc -l < "output.txt")
echo "Number of valid dates: $line_count" >> output.txt

#delete helper file
rm "output2.txt"