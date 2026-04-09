    require "HTTParty"
    require 'json'

    response = HTTParty.get('https://icanhazdadjoke.com/' , :headers => { 'Accept' => 'application/json' } )
    joke_object = JSON.parse(response.body)