#!/bin/bash

source ./config.sh

token=$1; shift
tagname=$1; shift
name=$1; shift
body=$1; shift
draft=$1; shift
prerelease=$1; shift
MSVC_RELEASE_PATH=$1; shift
MSVC_RELEASE_NAME=$1; shift

pushRelease() {    
    AUTHORIZATION="Authorization: Bearer $token"
    JSON_POST={\"tag_name\":\"$tagname\",\"target_commitish\":\"master\",\"name\":\"$name\",\"body\":\"$body\",\"draft\":$draft,\"prerelease\":$prerelease,\"generate_release_notes\":true}
    

    response=$(curl \
    -X 'POST' \
    https://api.github.com/repos/taljacob2/oop/releases \
    -H 'Accept: application/vnd.github+json' \
    -H "$AUTHORIZATION" \
    -H 'X-GitHub-Api-Version: 2022-11-28' \
    -d "$JSON_POST")

    echo "$response"
}

: '
Requirements:
Install `jq`. (It is a JSON parser that helps working with JSON).
```
sudo apt install jq
```
'
uploadAsset() {
    uploadAssetUrl=$1; shift
    assetPath=$1; shift
    assetName=$1; shift

    curl -X POST \
        -H "Content-Type: $(file -b --mime-type $assetPath)" \
        -T "$assetPath" \
        -H "Authorization: Bearer $token" \
        -H "Accept: application/vnd.github.v3+json" \
        "$uploadAssetUrl=$assetName"
}

# ---------------------------------- Code --------------------------------------

# Push release.
pushReleaseResponse=$(pushRelease)

# Get `upload_url` property from the response JSON.
uploadAssetUrl=`echo $pushReleaseResponse | jq -r '.upload_url'`

# Upload assets.
uploadAsset "$uploadAssetUrl" "$GCC_RELEASE_PATH" "$GCC_RELEASE_NAME"
uploadAsset "$uploadAssetUrl" "$MSVC_RELEASE_PATH" "$MSVC_RELEASE_NAME"


sleep 10