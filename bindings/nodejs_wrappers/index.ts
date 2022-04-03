import * as bindings from 'bindings'
const lib = bindings('dogecoinjs');

// TODO
// * fix ts definition to reflect return type based on as_bytes
// * add libdogecoin typescript definition

export enum Chain {
    mainnet = 0,
    testnet = 1,
}

export type StringOrBuffer = string | Buffer;

abstract class Dogecoin {
    private static startEccContext() {
        lib.dogecoinEccStart();
    }

    // private static stopEccContext() {
    //     lib.dogecoinEccStop();
    // }

    // private static isTestnet(chain_code: Chain) {
    //     return Boolean(chain_code);
    // }

    public static generatePrivPubKeyPair(/*chain_code: Chain, as_bytes: boolean = false*/): void { // [StringOrBuffer, StringOrBuffer] {
        this.startEccContext();

        // const keys = lib.generatePrivPubKeyPair(this.isTestnet(chain_code)) as [Buffer, Buffer]; // TODO remove

        // this.stopEccContext();

        // if (as_bytes) {
        //     return keys;
        // }

        // const [wif_privkey, p2pkh_pubkey] = keys as [Buffer, Buffer]; // TODO remove
        // return [wif_privkey.toString('utf-8'), p2pkh_pubkey.toString('utf-8')];
    }
}

export default Dogecoin;