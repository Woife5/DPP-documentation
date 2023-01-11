<script setup lang="ts">
import { ref } from 'vue'
import BasicDialog from '@/components/ui/dialogs/BasicDialog.vue'
import PrimaryButton from '@/components/ui/buttons/PrimaryButton.vue'

const dialog = ref<InstanceType<typeof BasicDialog>>()

function open() {
  dialog.value?.close()
}

function close() {
  dialog.value?.close()
}

defineExpose({
  open,
  close,
})
</script>

<template>
  <BasicDialog ref="dialog" :closable="false">
    <template v-slot:header>
      <h1 class="text-xl font-bold">Disclaimer</h1>
    </template>
    <PrimaryButton @click="close">Accept</PrimaryButton>
    <div>
      Lorem ipsum dolor sit amet, consectetur adipisicing elit. Repellat vel
      pariatur eius, quasi velit, maxime dolorum cumque officia quibusdam
      consequatur commodi autem nulla? Quasi ab possimus laboriosam, ratione
      dolores optio quod facere illo autem fugit porro, repellendus libero
      iusto. Natus sunt magnam blanditiis, aliquid deserunt vero ipsum maiores
      animi saepe repellendus enim, eligendi nostrum obcaecati! Maxime ipsum at
      inventore molestiae totam, dolor aperiam aliquid expedita incidunt, quas,
      ex quidem atque. Amet sed vitae nihil voluptatibus illo quidem perferendis
      ad molestias odit magni necessitatibus ipsum, assumenda repellat nemo
      laboriosam quos reprehenderit ipsam deleniti aliquid, eligendi quibusdam
      quas qui, esse provident. Neque cum saepe, fugit voluptas, porro corporis
      vero quis nam a voluptatem unde, explicabo consequatur illum? Qui voluptas
      consequuntur eveniet libero assumenda quas voluptates repellat nobis,
      autem possimus illo quae laborum sequi neque veritatis commodi id.
      Corrupti totam, omnis deleniti sequi ipsam unde, quo quibusdam numquam ea
      aperiam ad accusamus illo quia assumenda laudantium cumque ut. Ad sunt
      maiores a, doloribus ipsum quas mollitia veritatis laboriosam consectetur
      iure expedita dignissimos nihil sit. Hic libero cumque praesentium, rerum
      nesciunt nulla velit natus possimus minus unde, enim harum. Repudiandae
      deleniti consequatur porro voluptas adipisci animi, amet vel
      necessitatibus, voluptatem ducimus corrupti numquam perspiciatis,
      veritatis aperiam? Nihil ducimus quis nostrum repellendus! Eligendi
      officiis nemo quae est quisquam natus, error, doloremque quo eos ipsam
      odio quaerat et assumenda! Placeat ut quis totam, inventore eveniet
      pariatur beatae officia eaque non illum dolorem quas iste amet labore
      consequatur, possimus quidem veniam, ipsa ex eius similique! Voluptates
      sit omnis nesciunt est placeat? Dolore incidunt odit enim quaerat
      reprehenderit, explicabo vitae numquam voluptatum, adipisci earum tempora
      totam similique illum, dolorem facere deserunt natus ratione nisi
      blanditiis mollitia tempore iste! Excepturi odit expedita reiciendis iste
      et ea accusantium, officiis voluptate commodi nihil tenetur natus corrupti
      sit quam dicta. Sunt incidunt, repudiandae omnis harum reprehenderit
      voluptates cumque inventore exercitationem enim ea, odit debitis nam
      cupiditate animi iure. Amet aut fugiat neque est vel ut necessitatibus
      soluta ad dolore? Eius neque quas maxime voluptatem, reiciendis dolorem
      commodi soluta fugit, harum sed deleniti. Fugit consequatur dignissimos
      itaque cum facere doloribus id accusantium? Dolores vel maiores eligendi
      doloribus eaque modi, debitis voluptatem sit officia odit enim provident
      eos eius! Explicabo hic dolor magnam voluptatem pariatur! Similique ex
      aut, hic eum tempore facere voluptatem dicta consequatur placeat numquam
      neque dolores delectus maiores cum vel quae sapiente laudantium
      perferendis eligendi recusandae voluptatibus excepturi quis facilis natus!
      Aut, eligendi mollitia. Fugit ullam eligendi delectus necessitatibus,
      inventore cupiditate quaerat eveniet soluta sit voluptatem voluptas qui
      repellat voluptatum omnis expedita officia tenetur recusandae dicta quidem
      labore! Nam sunt dolorum facilis dolores eveniet odio porro quam omnis ex
      ab! Voluptas ea nisi quasi? Veniam atque quibusdam amet itaque vero
      praesentium aspernatur labore cum maiores eius voluptate explicabo facilis
      illum unde, pariatur animi? Unde accusamus qui deleniti ducimus natus. Qui
      atque magni tenetur eum, repellendus suscipit cupiditate quibusdam laborum
      repudiandae quaerat at dignissimos, eius necessitatibus quisquam officiis
      beatae velit! Architecto et nobis fugiat qui voluptate sunt saepe iusto
      soluta fugit voluptatum sapiente animi itaque deserunt quaerat,
      perspiciatis consectetur placeat dicta eveniet veniam temporibus
      reprehenderit perferendis sed, dolorem deleniti! Molestiae at quas, nulla,
      provident illum inventore dolorum excepturi vitae libero eius est sequi,
      molestias quibusdam temporibus quidem. Obcaecati dolores nemo unde
      sapiente quaerat impedit eos perspiciatis quia eaque doloribus vero
      recusandae voluptate eveniet id quis quisquam assumenda laudantium
      voluptatibus, laboriosam tempore necessitatibus et vitae. Harum veniam
      quis minima, aperiam necessitatibus odio at vel. Asperiores consectetur ut
      officia commodi at corrupti, animi molestias ea magnam distinctio deleniti
      voluptatibus, dolorum tempora minima veritatis, laborum laudantium
      laboriosam optio dicta? Aut corporis, voluptates est vitae illum libero,
      id quos qui, similique numquam voluptas obcaecati impedit praesentium.
      Voluptatem assumenda voluptatum illum, vero soluta est modi odit ad et
      incidunt consequatur nemo excepturi magni sequi recusandae atque esse?
      Voluptatem adipisci recusandae eaque autem, unde aspernatur deserunt quos
      aperiam dicta sapiente quasi? Animi quasi iusto recusandae fuga repellat,
      fugit, vitae, cupiditate deleniti eius nam harum explicabo distinctio
      accusantium ea ut nobis est nulla dolore. Officiis corrupti nulla
      voluptate autem! Repellendus, maxime, nulla ab corrupti architecto,
      voluptatem accusamus tempore iste consequuntur aliquam illo quas. Tenetur
      repellendus perspiciatis reprehenderit velit doloribus! Ad laboriosam
      laudantium magnam beatae soluta eveniet. A officia repellendus quibusdam
      error perspiciatis. Soluta fuga vero quam sunt maxime deleniti et dolore
      quaerat minus vel at saepe aliquid a aut corrupti illo, debitis nemo
      perferendis error ratione inventore molestiae cum aliquam. Dolores facilis
      consequatur modi eaque. Beatae pariatur nam quo ab aut unde, accusantium
      amet fugiat omnis id rerum illo at, repellat modi consectetur vitae
      accusamus ex asperiores libero! Hic aperiam consequuntur, doloremque
      deleniti et qui iure doloribus explicabo. Eaque perferendis, voluptatibus
      cupiditate eius ipsa numquam amet reiciendis ducimus! Facere atque autem
      repellat tenetur. Harum est explicabo temporibus natus accusamus deserunt
      pariatur quam ipsum illo, itaque aperiam repellendus fuga eius voluptas
      asperiores ipsam numquam, ipsa odio tenetur tempora, animi optio. Esse,
      reprehenderit id veniam vitae perferendis pariatur officiis voluptates,
      delectus odio alias assumenda doloribus laborum, ratione voluptatum
      debitis! Reiciendis ducimus dolor omnis distinctio quibusdam repellendus
      nulla sunt, dignissimos facilis provident praesentium. Quibusdam eos
      debitis nam ex eum ea deserunt ullam aut, ut molestiae quae aspernatur
      magni labore maxime? Nesciunt quas doloribus cumque hic voluptatem.
      Temporibus aperiam fugit culpa, unde quae nostrum pariatur iure,
      doloremque quas libero eaque. Facilis dolore qui quidem quod nostrum in
      porro atque, itaque obcaecati molestias impedit, adipisci debitis
      excepturi esse? Est libero, odit sit voluptas, voluptates harum quas iusto
      ut quis architecto voluptatum nulla praesentium nemo temporibus vero atque
      exercitationem sint corporis rerum repudiandae accusamus quaerat
      accusantium perspiciatis. In reiciendis eligendi ducimus fugit! Ratione
      beatae porro ullam dolor quia sequi eius modi temporibus consequuntur vero
      hic, inventore rerum dolorem. Natus placeat magnam, et pariatur quos
      accusamus corrupti sit consectetur veritatis dolore soluta accusantium.
      Nobis vitae explicabo ducimus praesentium tempora nulla maxime nam cumque
      fuga provident. Ut odio dicta adipisci eligendi illum. Iusto assumenda
      nisi distinctio quis rem. Nostrum, nam reprehenderit. Magnam obcaecati
      libero numquam velit dolorem dolores illo. Sapiente laudantium id nostrum
      animi sed ullam voluptatem.
    </div>
    <PrimaryButton @click="close">Close</PrimaryButton>
  </BasicDialog>
</template>
