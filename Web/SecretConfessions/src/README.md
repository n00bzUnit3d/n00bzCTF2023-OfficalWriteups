# Secrets | Spectral

Descritption - Upload all your secrets to my site. Don't corrupt me

# Writeup

The server allows you to upload files. You can upload a webshell using but a security mechanism deletes the file after saving it if it contains any bad characters. This can be exploited using a race condition, running the webshell after uploading but before the server has time to delete it. In order to render the webshell you must use a directory traversal attack with the filename of the webshell and upload the file into the templates directory. From there you can use the /mysecrets/<file> page to access the webshell

The flag will need to be set in an environment variable

# Flag - n00bz{th@t5_50m3_fr3@ky_5tuff}