#!/bin/bash

token=$1; shift
tagname=$1; shift
name=$1; shift
body=$1; shift
draft=$1; shift
prerelease=$1; shift

pushRelease() {
    echo $token
    echo $tagname
    echo $name
    echo $body
    echo $draft
    echo $prerelease
    
    AUTHORIZATION="Authorization: Bearer $token"
    JSON_POST={\"tag_name\":\"$tagname\",\"target_commitish\":\"master\",\"name\":\"$name\",\"body\":\"$body\",\"draft\":$draft,\"prerelease\":$prerelease,\"generate_release_notes\":true}
    

    curl -X 'POST' https://api.github.com/repos/taljacob2/oop/releases -H 'Accept: application/vnd.github+json' -H "$AUTHORIZATION" -H 'X-GitHub-Api-Version: 2022-11-28' -d "$JSON_POST"
}

# ---------------------------------- Code --------------------------------------

pushRelease


sleep 10