/**
 * @param {number} millis
 * @return {Promise}
 */
async function sleep(millis) {
    const d = new Date();
    let cd = new Date();
    while (cd - d < millis) {
        cd = new Date();
    }
    return;
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */