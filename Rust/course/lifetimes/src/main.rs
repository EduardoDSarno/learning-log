fn next_langauge<'a>(languages: &'a [String], current_language: &str) -> &'a str
{
    let mut found = false;

    for lang in languages{
        if found{
            return lang;
        }

        if lang == current_language{
            found = true;
        }
    }



    languages.last().unwrap() // for debugging
}


// this funciton will return the last item on the VEC
fn last_language (list: &[String]) -> &str
{
    return list.last().unwrap();
}

// this funciton returns the longest of the languages
fn longest_len<'a>(first: &'a str,second: &'a str)-> &'a str
{

    if first.len() >= second.len()
    {
        return first;
    }
    second
}
fn main() 
{
    let languages = vec![
        String::from("rust"),
        String::from("go"),
        String::from("typescript"),
    ];


}
